/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:08:10 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/14 10:54:13 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_allocator.h"
#include "token.h"

t_token	*create_token(t_token new_token)
{
	t_token	*token;

	token = safe_talloc(sizeof(t_token));
	if (!token)
		return (NULL);
	*token = new_token;
	token->next = NULL;
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

void	remove_token(t_token **head, t_token *prev, t_token *token)
{
	if (prev == NULL)
		*head = token->next;
	else
		prev->next = token->next;
	safe_free_ptr(token->content, TEMPORARY);
	safe_free_ptr(token, TEMPORARY);
}

void	prepend_token(t_token **head_token, t_token *new_token)
{
	if (*head_token == NULL)
		*head_token = new_token;
	else
	{
		new_token->next = *head_token;
		*head_token = new_token;
	}
}
