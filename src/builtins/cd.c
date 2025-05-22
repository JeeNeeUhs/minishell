/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:55:53 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/22 21:44:19 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "env.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	update_old_pwd()
{
	char	*pwd_val;

	pwd_val = get_env_value("PWD");
	if (pwd_val == NULL)
		pwd_val = "";
	set_env_value("OLDPWD", pwd_val);
}

int	cd_builtin(t_command *command)
{
	char	*path;
	char	*cwd;

	if (command->args[1] == NULL)
		path = get_env_value("HOME");
	else
		path = command->args[1];
	if (path == NULL)
		return (home_not_set());
	if (chdir(path) == -1)
	{
		perror("hash: cd");
		return (EXECUTION_FAILURE);
	}
	update_old_pwd();
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror("cd: error retrieving current directory: getcwd: cannot access parent directories");
		return (EXECUTION_SUCCESS); /* XXX -> THATS ABSOLUTELY TRUE*/
	}
	set_env_value("PWD", cwd);
	return (EXECUTION_SUCCESS);
}

