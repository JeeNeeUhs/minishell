/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 07:40:47 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/30 12:32:34 by ahekinci         ###   ########.fr       */
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
		set_exit_status(1);
		close(fd1);
		return (FAILURE);
	}
	close(fd1);
	return (SUCCESS);
}

int	set_std_fds(t_command *command)
{
	if (command->fd_in != STD_IN)
	{
		if (!do_dup(command->fd_in, STD_IN))
			return (FAILURE);
		command->fd_in = STD_IN;
	}
	if (command->fd_out != STD_OUT)
	{
		if (!do_dup(command->fd_out, STD_OUT))
			return (FAILURE);
		command->fd_out = STD_OUT;
	}
	return (SUCCESS);
}

void	close_pipe(t_command *command)
{
	if (command->fd_in != STD_IN)
		close(command->fd_in);
	if (command->fd_out != STD_OUT)
		close(command->fd_out);
}
