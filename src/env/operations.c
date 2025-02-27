/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:39:20 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/26 11:48:38 by hsamir           ###   ########.fr       */
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

/*
	Give unsafe_allocation parameter into this func
	Cuz if we cleanup the  memory allocated by memory-allacator
	we will lose env key-value pairs.
*/
void	set_env_value(char *key, char *value)
{
	t_env	*env;

	env = get_env(key);
	if (env == NULL)
	{
		env = create_env(key, value);
		if (!env)
			remove_all_env();
		return ;
	}
	free(env->value);
	env->value = value;
}

void	init_env(char *envp[])
{
	char	*key;
	char	*value;
	int		i;
	int		s_index;

	i = 0;
	while (envp[i])
	{
		s_index = find_char_index(envp[i], 0, '=');
		key = ft_unsafe_substr(envp[i], 0, s_index);
		value = ft_unsafe_substr(envp[i], s_index + 1, ft_strlen(envp[i]) - s_index - 1);
		if (!value || !key)
		{	
			free(value);
			free(key);
			remove_all_env();
			safe_exit(1, "Allocation Error");
		}
		if (!create_env(key, value))
			safe_exit(1, "Allocation Error");
		i++;
	}
}
