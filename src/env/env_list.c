/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:28:00 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/30 12:15:24 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "minishell.h"
#include "memory_allocator.h"
#include "string_utils.h"

t_env	**get_head_env(void)
{
	static t_env	*root_env = {0};

	return (&root_env);
}

void	prepend_env(t_env **head_env, t_env *new_env)
{
	if (*head_env == NULL)
		*head_env = new_env;
	else
	{
		new_env->next = *head_env;
		*head_env = new_env;
	}
}

t_env	*create_env(char *key, char *value)
{
	t_env	*new_env;
	t_env	**head_env;

	head_env = get_head_env();
	new_env = safe_palloc(sizeof(t_env));
	*new_env = (t_env){
		.key = ft_pstrdup(key),
		.value = ft_pstrdup(value),
		.next = NULL
	};
	prepend_env(head_env, new_env);
	return (new_env);
}

void	remove_env(char *key)
{
	t_env	**head_env;
	t_env	*prev_env;
	t_env	*cur_env;

	if (!key)
		return ;
	head_env = get_head_env();
	prev_env = NULL;
	cur_env = *head_env;
	while (cur_env)
	{
		if (str_equal(cur_env->key, key))
		{
			if (prev_env == NULL)
				*head_env = cur_env->next;
			else
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
	*get_head_env() = NULL;
}
