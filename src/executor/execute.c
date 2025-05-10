/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:41:39 by ahekinci          #+#    #+#             */
/*   Updated: 2025/05/10 04:00:48 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "env.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
notes
if the t_command struct have a next pointer, it means i should create a pipe
the t_command struct for now first arg is command path
*/

void executor(t_command *command)
{
	int 	pid;
	int		prev[2];
	int		next[2];

	prev[0] = -1;
	prev[1] = -1;
	next[0] = -1;
	next[1] = -1;

	if (!command->next)
	{
		//run single command
		pid = fork();
		if (pid == 0)
		{
			if (command->fd_in != STD_IN)
				dup2(command->fd_in, STD_IN);
			if (command->fd_out != STD_OUT)
				dup2(command->fd_out, STD_OUT);
			execve(command->args[0], command->args, NULL); 
		}
		else
		{
			waitpid(pid, NULL, 0);
			return;
		}
	}
	
	while (command)
	{
		if (prev[0] != -1)
		{
			close(prev[0]);
			close(prev[1]);
		}
		prev[0] = next[0];
		prev[1] = next[1];
		if (command->next)
		{
			if (pipe(next) == -1)
			{
				// handle error
				exit(EXIT_FAILURE);
			}
			
		}
		else
		{
			next[0] = -1;
			next[1] = -1;
		}
		pid = fork();
		if (pid == 0)
		{
			if (command->fd_in != STD_IN)
				dup2(command->fd_in, STD_IN);
			if (command->fd_out != STD_OUT)
				dup2(command->fd_out, STD_OUT);
			if (prev[0] != -1)
				dup2(prev[0], STD_IN);
			if (next[1] != -1)
				dup2(next[1], STD_OUT);
			execve(command->args[0], command->args, NULL);
		}
	}
}



