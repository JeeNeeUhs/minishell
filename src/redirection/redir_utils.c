/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 07:40:47 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/22 08:03:00 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "command.h"
#include "stdio.h"
#include "unistd.h"

int	do_dup(int fd1, int fd2)
{
	if (dup2(fd1, fd2) < 0)
	{
		perror("dup2");
		*exit_status() = 1;
		close(fd1);
		return (FAILURE);
	}
	close(fd1);
	return (SUCCESS);
}


int	set_std_fds(t_command *command)
{
	int	return_value;

	return_value = SUCCESS;
	if (should_fork(command))
		return (SUCCESS);
	if (command->fd_in != STD_IN)
	{
		if (!do_dup(command->fd_in, STD_IN))
			return_value = FAILURE;
	}
	if (command->fd_out != STD_OUT)
	{
		if (return_value && !do_dup(command->fd_out, STD_OUT))
			return_value = FAILURE;
	}
	return (return_value);
}
