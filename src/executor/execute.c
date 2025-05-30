/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:04:29 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/30 06:22:11 by hsamir           ###   ########.fr       */
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

int	execute_builtin(t_command *command)
{
	t_builtin	builtin;
	int			exit_value;

	builtin = get_builtin(command->args[0]);
	exit_value = builtin(command);
	return (exit_value);
}

int	execute_disk_command(t_command *command)
{
	char	**envp;
	char	*full_path;

	if (command->args[0] == NULL)
		return (EXECUTION_SUCCESS);
	full_path = search_command_path(command->args[0]);
	if (full_path == NULL)
		command_not_found(command->args[0]);
	command->args[0] = full_path; /* XXX */
	envp = get_env_to_array();
	execve(full_path, command->args, envp);
	return (EX_NOEXEC);
}

void	execute_simple_command(t_command *command)
{
	int	exit_value;

	if (!do_redirection(command))
		exit_value = EXECUTION_FAILURE;
	else
		exit_value = execute_builtin(command);
	set_exit_status(exit_value);
}

void	execute_command(t_command *command)
{
	if (need_subshell(command))
		execute_pipeline(command);
	else
		execute_simple_command(command);
}
