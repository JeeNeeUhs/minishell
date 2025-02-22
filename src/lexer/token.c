/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:08:10 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/22 10:35:54 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "memory-allocator.h"

t_token	*create_token(t_token**	head_token, char* content, t_token_type type)
{
	t_token	*token;

	token = ft_malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	*token = (t_token){.content = content, .type = type, .next = NULL};
	append_token(head_token, token);
	return (token);
}

t_token	*get_last_token(t_token *head_token)
{
	t_token	*last_token;

	last_token = head_token;
	while (last_token->next)
		last_token = last_token->next;
	return (last_token);
}

void	append_token(t_token **head_token, t_token *new_token)
{
	t_token	*last_token;

	if (!*head_token)
	{
		*head_token = new_token;
		return ;
	}
	last_token = get_last_token(*head_token);
	last_token->next = new_token;
}
