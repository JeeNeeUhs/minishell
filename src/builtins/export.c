/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:12:55 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/30 12:14:10 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "stddef.h"
#include "minishell.h"
#include "env.h"
#include "builtins.h"
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

int	is_valid_identifier(char *variable)
{
	int	index;

	index = 0;
	if (!ft_isalpha(variable[0]) && variable[0] != '_')
		return (0);
	while (is_var_char(variable[index]))
		index++;
	return (variable[index] == '\0' || variable[index] == '=');
}

int	export_builtin(t_command *cmd)
{
	char	**args;
	int		offset;
	int		exit_code;

	if (cmd->args[1] == NULL)
		print_export(cmd->fd_out);
	args = cmd->args;
	exit_code = EXECUTION_SUCCESS;
	while (*++args != NULL)
	{
		if (!is_valid_identifier(*args))
			exit_code = report_export_error(*args);
		else
		{
			offset = find_char_index(*args, 0, '=');
			if ((*args)[offset] == '\0')
				set_env_value(*args, NULL);
			else
			{
				(*args)[offset] = '\0';
				set_env_value(*args, *args + offset + 1);
			}
		}
	}
	return (exit_code);
}
