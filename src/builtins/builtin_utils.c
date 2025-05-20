/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:26:40 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/20 17:33:36 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "string_utils.h"

int	is_builtin(char *command)
{
	return (
		str_equal(command, "cd")
		|| str_equal(command, "echo")
		|| str_equal(command, "env")
		|| str_equal(command, "exit")
		|| str_equal(command, "export")
		|| str_equal(command, "pwd")
		|| str_equal(command, "unset")
	);
}

t_builtin	get_builtin(char *command)
{
	if (str_equal(command, "cd"))
		return (cd_builtin);
	else if (str_equal(command, "echo"))
		return (echo_builtin);
	else if (str_equal(command, "env"))
		return (env_builtin);
	else if (str_equal(command, "exit"))
		return (exit_builtin);
	else if (str_equal(command, "export"))
		return (export_builtin);
	else if (str_equal(command, "pwd"))
		return (pwd_builtin);
	else if (str_equal(command, "unset"))
		return (unset_builtin);
	return (NULL);
}
