/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:18:32 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/27 10:27:40 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include "libft.h"
#include "command.h"
#include "memory_allocator.h"
#include <stdio.h>

int	report_export_error(char* variable)
{
	ft_putstr_fd("hash: export: `", 2);
	ft_putstr_fd(variable, 2);
	ft_putstr_fd("`: not a valid identifier\n", 2);
	*exit_status() = 1;
	return (EXECUTION_FAILURE);
}

void	command_not_found(char *command)
{
	ft_putstr_fd("hash: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
	safe_abort(EX_NOTFOUND);
}

int	builtin_error(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	*exit_status() = 1;
	return (EXECUTION_FAILURE);
}

void	abort_command(char *command, int status)
{
	ft_putstr_fd("hash: ", 2);
	perror(command);
	safe_abort(status);
}

