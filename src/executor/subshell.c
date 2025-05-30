/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:16:03 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/30 12:17:50 by ahekinci         ###   ########.fr       */
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

	if (!do_redirection(command) || !set_std_fds(command))
		safe_abort(EXECUTION_FAILURE);
	if (is_builtin(command->args[0]))
		exit_value = execute_builtin(command);
	else
		exit_value = execute_disk_command(command);
	safe_abort(exit_value);
}

void	execute_pipeline(t_command *command)
{
	pid_t	last_pid;

	set_signal_handler(EXEC_SIG);
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
