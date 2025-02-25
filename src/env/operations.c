/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:39:20 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/25 17:17:37 by ahekinci         ###   ########.fr       */
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

void	init_env(char *envp[])
{
	int	i;
	char	*eql;
	char	*key;
	char	*value;

	i = 0;
	while (envp[i])
	{
		eql = ft_strchr(envp[i], '=');
		if (eql)
		{
			key = ft_substr(envp[i], 0, eql - envp[i]); // hata kotnrolu nasil olcuak
			value = ft_strdup(eql + 1);
			create_env(key, value);
		}
		// else olmasi lazim mi?
		i++;
	}
}
