/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:12:55 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/20 14:05:56 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "stddef.h"
#include "minishell.h"
#include "env.h"
#include "builtin.h"
#include "string_utils.h"
#include "libft.h"

void	print_export(int fd)
{
	t_env	*env;

	env = *get_head_env();
	while (env != NULL)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(env->key, fd);
		if (env->value != NULL)
		{
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(env->value, fd);
			ft_putstr_fd("\"", fd);
		}
		ft_putstr_fd("\n", fd);
		env = env->next;
	}
}
int	is_valid_identifier(char* variable)
{
	int	index;

	index = 0;
	if (!ft_isalpha(variable[0]) && variable[0] != '_') //%_test -> $1 $2 We didn't implement positional parameters, but bash manual says "do not begin with a digit"
		return (0);
	while (is_var_char(variable[index])) //a%bcdef%=
		index++;
	return (variable[index] == '\0' || variable[index] == '=');
}

void	export_builtin(t_command *command)
{
	char	*variable;
	int		offset;
	int		index;

	if (command->args[1] == NULL)
		print_export(command->fd_out);
	index = 1;
	while (command->args[index] != NULL)
	{
		variable = command->args[index];
		if (!is_valid_identifier(variable))
			report_export_error(variable);
		else
		{
			offset = find_char_index(variable, 0, '=');
			if (variable[offset] == '\0')
				set_env_value(variable, NULL);
			else
			{
				variable[offset] = '\0';
				set_env_value(variable, variable + offset + 1);
			}
		}
		index++;
	}
}
