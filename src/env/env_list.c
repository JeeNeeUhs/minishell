/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:28:00 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/27 16:22:24 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "memory-allocator.h"

t_env	*get_root_env(void)
{
	static t_env	root_env = {0};

	return (&root_env);
}

t_env	*get_last_env(void)
{
	t_env	*env;

	env = get_root_env();
	while (env->next)
		env = env->next;
	return (env);
}

t_env	*create_env(char *key, char *value)
{
	t_env	*new_env;

	new_env = safe_palloc(sizeof(t_env));
	*new_env = (t_env){
		.key = ft_pstrdup(key),
		.value = ft_pstrdup(value),
		.next = NULL
	};
	get_last_env()->next = new_env;
	return (new_env);
}

void	remove_env(char *key)
{
	t_env	*prev_env;
	t_env	*cur_env;

	if (!key)
		return ;
	prev_env = get_root_env();
	cur_env = prev_env->next;
	while (cur_env)
	{
		if (str_equal(cur_env->key, key))
		{
			prev_env->next = cur_env->next;
			safe_free_ptr(cur_env->key, PERSISTENT);
			safe_free_ptr(cur_env->value, PERSISTENT);
			safe_free_ptr(cur_env, PERSISTENT);
			break ;
		}
		prev_env = cur_env;
		cur_env = prev_env->next;
	}
}

void	remove_all_env(void)
{
	safe_free(PERSISTENT);
	get_root_env()->next = NULL;
}
