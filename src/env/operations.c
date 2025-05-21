/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:39:20 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/21 16:41:13 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "minishell.h"
#include "memory_allocator.h"
#include "string_utils.h"

t_env	*get_env(char *key)
{
	t_env	*env;

	env = *get_head_env();
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
	t_env	*env;

	env = get_env(key);
	if (env == NULL)
		return (NULL);
	return (env->value);
}

void	set_env_value(char *key, char *value)
{
	t_env	*env;

	env = get_env(key);
	if (env == NULL)
		create_env(key, value);
	else if (value != NULL)
	{
		safe_free_ptr(env->value, PERSISTENT);
		env->value = ft_pstrdup(value);
	}
}

void	init_env(char *envp[])
{
	char	*variable;
	int		index;
	int		offset;

	index = 0;
	while (envp[index])
	{
		variable = ft_strdup(envp[index]);
		offset = find_char_index(variable, 0, '=');
		variable[offset] = '\0';
		create_env(
			variable,
			variable + offset + 1
		);
		index++;
		safe_free_ptr(variable, TEMPORARY);
	}
}

char	**get_env_to_array(void)
{
	t_env	*head_env;
	t_env	*env;
	char	**array;
	int		index;
	int		len;

	head_env = *get_head_env();
	env = head_env;
	len = 0;
	while (env != NULL)
	{
		len += (env->value != NULL);
		env = env->next;
	}
	env = head_env;
	array = safe_talloc((len + 1) * sizeof(char *));
	index = 0;
	while (env != NULL)
	{
		if (env->value != NULL)
			array[index++] = str_arr_join((char *[]){env->key, "=", env->value}, 3);
		env = env->next;
	}
	array[index] = NULL;
	return (array);
}
