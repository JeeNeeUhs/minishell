/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:41:52 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/30 22:49:14 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int	pwd_builtin(t_command *command)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror("pwd");
		return (EXECUTION_FAILURE);
	}
	ft_putstr_fd(cwd, command->fd_out);
	ft_putchar_fd('\n', command->fd_out);
	free(cwd);
	return (EXECUTION_SUCCESS);
}
