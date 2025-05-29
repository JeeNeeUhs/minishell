/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:49:19 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/29 08:20:03 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "minishell.h"
#include "builtins.h"
#include <sys/wait.h>
#include <unistd.h>
#include "string_utils.h"
#include <stdio.h>

int	should_fork(t_command *command)
{
	return (
		!is_builtin(command->args[0]) ||
		command->prev != NULL ||
		command->next != NULL);
}

int	make_pipe(t_command *command)
{
	int	fd[2];

	if (pipe(fd) < 0)
	{
		perror("pipe error");
		set_exit_status(EXECUTION_FAILURE);
		return (FAILURE);
	}
	command->fd_out = fd[1];
	command->next->fd_in = fd[0];
	return (SUCCESS);
}

pid_t	make_child()
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		set_exit_status(EX_NOEXEC);
	}
	return (pid);
}

void	wait_children(pid_t last_pid)
{
	int	exit_code;

	exit_code = 0;
	if (last_pid > 0)
	{
		waitpid(last_pid, &exit_code, 0);
		set_exit_status(WEXITSTATUS(exit_code)); // [SIGNAL | FLAG] (EXIT_CODE & 255) >> 8;
	}
	while (wait(NULL) > 0)
		;
}

