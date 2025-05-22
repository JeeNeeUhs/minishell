/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:04:29 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/22 05:58:29 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "builtins.h"
#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "env.h"

void	execute_builtin(t_command *command)
{
	t_builtin	builtin;
	int			exit_value;

	builtin = get_builtin(command->args[0]);
	exit_value = builtin(command) & 255;
	if (should_fork(command))
		exit(exit_value);
	*exit_status() = exit_value;
}

void	execute_disk_command(t_command *command)
{
	char	**envp;

	envp = get_env_to_array();
	execve(command->args[0], command->args, envp);
}

void	execute_command(t_command *command)
{
	*exit_status() = 0;
	if (!do_redirection(command)) //todo eğer redir error  varsa ne yapacagız ? pipe varsa exit pipe yoksa return ; atmak bile çözüm değil çünkü builtin değil ve tek komutsa yine exit değilse return atmalı
		return ;
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
		if (command->next != NULL && !make_pipe(command))
				break ;
		if (should_fork(command))
			last_pid = make_child();
		if (last_pid < 0)
			break ;
		if (last_pid == 0)
			execute_command(command);
		close_fds(command);
		command = command->next;
	}
	wait_children(last_pid);
}
