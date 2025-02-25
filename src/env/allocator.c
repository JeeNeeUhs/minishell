/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:28:00 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/25 16:19:19 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

t_env	*get_root_env(void)
{
	static t_env	root_env = {0};

	return (&root_env);
}

t_env	*get_last_env(void)
{
	t_env	*env;

	env = get_root_env();
	while (env)
		env = env->next;
	return (env);
}

t_env	*create_env(char *key, char *value)
{
	t_env	*new_env;
	char	*new_val;

	new_env = malloc(sizeof(t_env));
	new_val = malloc(ft_strlen(value) + 1);
	if (!new_env || !new_val)
	{
		remove_all_env();
		return (NULL);
	}
	ft_strlcpy(new_val, value, ft_strlen(value) + 1);
	*new_env = (t_env){.key = key, .value = new_val, .next = NULL};
	get_last_env()->next = new_env;
	return (new_env);
}
