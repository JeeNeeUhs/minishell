/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 08:59:01 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/11 23:50:36 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <unistd.h>
#include <stdio.h>
#include <minishell.h>
#include <fcntl.h>

int	get_flags(t_instruction instruction)
{
	int	flags;

	flags = 0;
	if (instruction & I_APPEND)
		flags = O_APPEND | O_CREAT | O_WRONLY;
	else if (instruction & I_OUT)
		flags = O_TRUNC | O_CREAT | O_WRONLY;
	else if (instruction & I_IN)
		flags = O_RDONLY;
	else if (instruction & I_HERE)
		flags = O_CREAT | O_TRUNC | O_RDWR;
	return (flags);
}

int	open_redir_file(t_redirect *redirecs)
{
	int	flags;
	int	fd;

	flags = get_flags(redirecs->instruction);
	fd = open(redirecs->file_name, flags, 0644);
	if (fd == -1)
		perror(redirecs->file_name);
	return (fd);
}

void	set_new_fd(t_command *command, t_instruction instruction, int fd)
{
	if(instruction & FD_IN && command->fd_in != STD_IN)
		close(command->fd_in);
	if (instruction & FD_IN)
		command->fd_in = fd;
	if(instruction & FD_OUT && command->fd_out != STD_OUT)
		close(command->fd_out);
	if(command->fd_out = fd)
		command->fd_out = fd;
}
void	make_redirection(t_command *command)
{
	t_redirect	*redirect;
	size_t		redir_count;
	size_t		index;
	int			fd;

	fd = 0;
	index = 0;
	redir_count = command->redir_count;
	while (index < redir_count)
	{
		redirect = &command->redirecs[index];
		if (redirect->instruction & I_HERE)
			fd = make_here_document(redirect);
		else
			fd = open_redir_file(redirect);
		set_new_fd(command, redirect->instruction, fd);
		if (fd == -1)
		{
			*exit_status() = 1;
			break ;
		}
		index += 1;
	}
}
void	do_redirections(t_command *commands)
{
	while (commands)
	{
		make_redirection(commands);
		commands = commands->next;
	}
}
