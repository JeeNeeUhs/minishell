/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:41:39 by ahekinci          #+#    #+#             */
/*   Updated: 2025/05/12 14:27:19 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "minishell.h"
#include "env.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

/*
notes
if the t_command struct have a next pointer, it means i should create a pipe
the t_command struct for now first arg is command path
*/

void set_export(char *new)
{
	char	*key;
	char	*value;
	int		index;

	if (new == NULL)
		return ;
	index = find_char_index(new, 0, '=');
	new[index] = '\0';
	key = ft_pstrdup(new);
	value = ft_pstrdup(&new[index + 1]);
	set_env_value(key, value);
}


void	executor(t_command *command)
{
	int 	pid;
	int		prev[2];
	int		next[2];

	prev[0] = -1;
	prev[1] = -1;
	next[0] = -1;
	next[1] = -1;

	if(command->args[0] != NULL && str_equal(command->args[0], "export"))
	{
		set_export(command->args[1]);
		return ;
	}
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
		exit(pid);
	}

	// while (command)
	// {
	// 	if (prev[0] != -1)
	// 	{
	// 		close(prev[0]);
	// 		close(prev[1]);
	// 	}
	// 	prev[0] = next[0];
	// 	prev[1] = next[1];
	// 	if (command->next)
	// 	{
	// 		if (pipe(next) == -1)
	// 		{
	// 			// handle error
	// 			exit(EXIT_FAILURE);
	// 		}

	// 	}
	// 	else
	// 	{
	// 		next[0] = -1;
	// 		next[1] = -1;
	// 	}
	// 	pid = fork();
	// 	if (pid == 0)
	// 	{
	// 		if (command->fd_in != STD_IN)
	// 			dup2(command->fd_in, STD_IN);
	// 		if (command->fd_out != STD_OUT)
	// 			dup2(command->fd_out, STD_OUT);
	// 		if (prev[0] != -1)
	// 			dup2(prev[0], STD_IN);
	// 		if (next[1] != -1)
	// 			dup2(next[1], STD_OUT);
	// 		execve(command->args[0], command->args, NULL);
	// 	}
	// }
}

