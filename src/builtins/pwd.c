/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:41:52 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/20 14:21:55 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "minishell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

/* Print the name of the current working directory. */
void	pwd_builtin(t_command *command)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror("pwd");
		*exit_status() = 1;
		return ;
	}
	ft_putstr_fd(cwd, command->fd_out);
	ft_putchar_fd('\n', command->fd_out);
	free(cwd);
}
