/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:16:03 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/29 23:53:18 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "minishell.h"
#include <unistd.h>
#include "memory_allocator.h"
#include "builtins.h"

pid_t	make_subshell(t_command *command)
{
	pid_t	pid;

	if (command->next != NULL && !make_pipe(command))
		return (-1);
	pid = make_child();
	if (pid == 0 && command->next != NULL)
		close(command->next->fd_in);
	if (pid < 0 && command->next != NULL)
		close(command->next->fd_in);
	return (pid);
}
void	execute_in_subshell(t_command *command)
{
	int	exit_value;

	set_signal_handler(EXEC_SIG);
	if (!do_redirection(command) || !set_std_fds(command))
		safe_abort(EXECUTION_FAILURE);
	if (is_builtin(command->args[0]))
		exit_value = execute_builtin(command);
	else
		exit_value = execute_disk_command(command);
	safe_abort(exit_value);
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
	pid_t	last_pid;

	while (command != NULL)
	{
		last_pid = make_subshell(command);
		if (last_pid == 0)
			execute_in_subshell(command);
		close_pipe(command);
		if (last_pid < 0)
			break ;
		command = command->next;
	}
	wait_children(last_pid);
}
