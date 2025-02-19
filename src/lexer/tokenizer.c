/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:32:31 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/17 14:28:08 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-allocator.h"
#include "minishell.h"
#include "../libft/libft.h"

t_token	*create_token(void* data, t_token_type type)
{
	t_token	*token;

	token = ft_malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	*token = (t_token){.data = data, .type = type, .next = NULL};
	return (token);
}

t_token	*tokenizer(char *str)
{
	t_token	*tokens;
	int		i;

	tokens = NULL;
	i = 0;
	while (str[i])
	{
	}
	return (tokens);
}
