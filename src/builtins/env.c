/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 23:23:23 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/21 19:09:07 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"
#include "command.h"

int	env_builtin(t_command *command)
{
	t_env	*env;

	env = *get_head_env();
	while (env != NULL)
	{
		if (env->value != NULL)
		{
			ft_putstr_fd(env->key, command->fd_out);
			ft_putstr_fd("=", command->fd_out);
			ft_putstr_fd(env->value, command->fd_out);
			ft_putstr_fd("\n", command->fd_out);
		}
		env = env->next;
	}
	return (EXECUTION_SUCCESS);
}
