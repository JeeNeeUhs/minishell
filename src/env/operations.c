/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:39:20 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/25 16:14:09 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"

t_env	*get_env(char *key)
{
	t_env	*env;

	env = get_root_env();
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

int	set_env_value(char *key, char *value)
{
	t_env	*env;
	char	*new_val;

	new_val = malloc (size)
	env = get_env(key);
	if (env == NULL)
	{
		env = create_env(key, ft_strdup(value));
		if (env)
	}
	else
	{
		free(env->value);
		env->value = ft_strdup(value);
	}
}

void	init_env(char *envp[]);
