/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:04:29 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/29 08:41:00 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "builtins.h"
#include "minishell.h"
#include "memory_allocator.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "env.h"

void	execute_builtin(t_command *command)
{
	t_builtin	builtin;
	int			exit_value;

	if (!do_redirection(command))
	{
		if (should_fork(command))
			safe_abort(EXECUTION_FAILURE);
		return ;
	}
	if (should_fork(command) && !set_std_fds(command))
		safe_abort(EXECUTION_FAILURE);
	builtin = get_builtin(command->args[0]);
	exit_value = builtin(command);
	if (should_fork(command))
		safe_abort(exit_value);
	set_exit_status(exit_value);
}

void	execute_disk_command(t_command *command)
{
	char	**envp;
	char	*full_path;

	if (!do_redirection(command) || !set_std_fds(command))
		safe_abort(EXECUTION_FAILURE);
	if (command->args[0] == NULL)
		safe_abort(EXECUTION_SUCCESS);
	full_path = search_command_path(command->args[0]);
	if (full_path == NULL)
		command_not_found(command->args[0]);
	command->args[0] = full_path;
	envp = get_env_to_array();
	execve(full_path, command->args, envp);
	safe_abort(EX_NOEXEC);
}

void	execute_command(t_command *command)
{
	if (command->next != NULL) // fork açtıgında next'in fdsinde pipeın diğer ucunu tutuyoruz fakat kapamıyoruz bu yüzde read cagrısında refcount 0 olmadıgı için bloklanıyor.
		close(command->next->fd_in);
	if (is_builtin(command->args[0]))
		execute_builtin(command);
	else
		execute_disk_command(command);
}

/* Execute a simple command that is hopefully defined in a disk file
   somewhere.

   1) fork ()
   2) connect pipes
   3) look up the command
   4) do redirections
   5) execve ()
   6) If the execve failed, see if the file has executable mode set.
   If so, and it isn't a directory, then execute its contents as
   a shell script.

   Note that the filename hashing stuff has to take place up here,
   in the parent.  This is probably why the Bourne style shells
   don't handle it, since that would require them to go through
   this gnarly hair, for no good reason.

   NOTE: callers expect this to fork or exit(). */
void	execute_pipeline(t_command *command)
{
	pid_t		last_pid;

	while (command != NULL)
	{
		last_pid = 0;
		set_signal_handler(EXEC_SIG);
		if (command->next != NULL && !make_pipe(command))
				break ;
		if (should_fork(command))
			last_pid = make_child();
		if (last_pid < 0)
		{
			close_fds(command);
			break ;
		}
		if (last_pid == 0)
			execute_command(command);
		close_fds(command);
		command = command->next;
	}
	wait_children(last_pid);
}
