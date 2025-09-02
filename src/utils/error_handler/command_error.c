/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:18:32 by hsamir            #+#    #+#             */
/*   Updated: 2025/09/02 17:59:53 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "command.h"
#include "memory_allocator.h"
#include <stdio.h>
#include <sys/wait.h>

int	report_export_error(char *variable)
{
	ft_putstr_fd("hash: export: `", 2);
	ft_putstr_fd(variable, 2);
	ft_putstr_fd("`: not a valid identifier\n", 2);
	set_exit_status(1);
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
	set_exit_status(1);
	return (EXECUTION_FAILURE);
}

void	abort_command(char *command, int status)
{
	ft_putstr_fd("hash: ", 2);
	perror(command);
	safe_abort(status);
}

void	print_pipeline(int exit_code)
{
	int	signal_num;
	
	signal_num = WTERMSIG(exit_code);
	if (!WIFSIGNALED(exit_code))
		return ;
	if (signal_num == SIGQUIT)
		ft_putstr_fd("Quit", 2);
	if (signal_num == SIGSEGV)
		ft_putstr_fd("Segmentation fault", 2);
	if (signal_num == SIGABRT)
		ft_putstr_fd("Aborted", 2);
	if (signal_num == SIGFPE)
		ft_putstr_fd("Floating point exception", 2);
	if (signal_num == SIGBUS)
		ft_putstr_fd("Bus error", 2);
	if (signal_num == SIGTRAP)
		ft_putstr_fd("Trace/breakpoint trap", 2);
	if (WCOREDUMP(exit_code))
		ft_putstr_fd(" (core dumped)\n", 2);
	if (signal_num == SIGINT)
  		ft_putstr_fd("\n", 2);
}
