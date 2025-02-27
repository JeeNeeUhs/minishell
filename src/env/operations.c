/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:39:20 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/27 15:40:35 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"

t_env	*get_env(char *key)
{
	t_env	*env;

	env = get_root_env()->next;
	while (env)
	{
		if (str_equal(env->key, key))
			return (env);
		env = env->next;
	}
	return (NULL);
}

char	*get_env_value(char *key)
{
	return (get_env(key)->value);
}

void	set_env_value(char *key, char *value)
{
	t_env	*env;

	env = get_env(key);
	if (env == NULL)
		create_env(key, value);
	else
		env->value = ft_pstrdup(value);
}

void	init_env(char *envp[])
{
	int		equal_index;
	int		i;

	i = 0;
	while (envp[i])
	{
		equal_index = find_char_index(envp[i], 0, '=');
		create_env(
			ft_psubstr(envp[i], 0, equal_index),
			ft_pstrdup(&envp[i][equal_index + 1])
			);
		i++;
	}
}
