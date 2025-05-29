/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:55:53 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/28 19:57:49 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "env.h"
#include <stdlib.h>
#include "builtins.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void	update_pwd_env()
{
	char	*pwd_val;
	char	*cwd;

	pwd_val = get_env_value("PWD");
	if (pwd_val == NULL)
		pwd_val = "";
	set_env_value("OLDPWD", pwd_val);
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		perror("getcwd: cannot access parent directories"); /* XXX -> THATS ABSOLUTELY TRUE*/
	else
		set_env_value("PWD", cwd);
	free(cwd);
}

/* source code: https://pastes.dev/mWxHaBhbR1 */
int	cd_builtin(t_command *command)
{
	char	*dir_name;

	if (command->args[1] && command->args[2])
		return (builtin_error(" too many arguments"));
	dir_name = command->args[1];
	if (dir_name == NULL)
		dir_name = get_env_value("HOME"); /* `cd' without arguments is equivalent to `cd $HOME' */
	if (dir_name == NULL)
		return (builtin_error("hash cd: HOME is not set"));
	if (chdir(dir_name) == -1)
	{
		ft_putstr_fd("hash cd ", 2);
		perror(dir_name);
		return (EXECUTION_FAILURE);
	}
	update_pwd_env();
	return (EXECUTION_SUCCESS);
}
