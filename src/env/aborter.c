/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_aborter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:34:19 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/25 11:18:58 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "minishell.h"

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
			free(cur_env->key);
			free(cur_env->value);
			free(cur_env);
			break ;
		}
		prev_env = cur_env;
		cur_env = prev_env->next;
	}
}

void	remove_all_env(void)
{
	t_env	*cur_env;
	t_env	*next_env;

	cur_env = get_root_env()->next;
	while (cur_env)
	{
		next_env = cur_env->next;
		free(cur_env->key);
		free(cur_env->value);
		free(cur_env);
		cur_env = next_env;
	}
}
