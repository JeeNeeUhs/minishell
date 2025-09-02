/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:49:19 by hsamir            #+#    #+#             */
/*   Updated: 2025/09/02 16:28:23 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "minishell.h"
#include "builtins.h"
#include <sys/wait.h>
#include <unistd.h>
#include "string_utils.h"
#include <stdio.h>
#include "libft.h"

int	need_subshell(t_command *command)
{
	return (
		!is_builtin(command->args[0])
		|| command->prev != NULL
		|| command->next != NULL);
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

pid_t	make_child(void)
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

void	wait_children(pid_t last_pid) /*XXX https://pastes.dev/zOoKvNOIP2 */
{
	int	exit_code;

	exit_code = 0;
	if (last_pid > 0)
	{
		waitpid(last_pid, &exit_code, 0);
		if (WIFEXITED(exit_code))
			set_exit_status(WEXITSTATUS(exit_code));
		else
			set_exit_status(128 + WTERMSIG(exit_code));
		if (WIFSTOPPED(exit_code) == 0)
			print_pipeline(exit_code);
	}
	while (wait(NULL) > 0)
		;
}

void	fini_func(void *params)
{
	close_fds(params);
}
