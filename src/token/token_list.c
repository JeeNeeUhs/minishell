/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:08:10 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/03 14:21:29 by hsamir           ###   ########.fr       */
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

void	remove_token_by_flags(t_token **head_token, int flags)
{
	t_token	*prev_token;
	t_token	*next_token;
	t_token	*token;

	prev_token = NULL;
	token = *head_token;
	while (token != NULL)
	{
		next_token = token->next;
		if (token->type & flags)
			remove_token(head_token, prev_token, token);
		else
			prev_token = token;
		token = next_token;
	}
}

void	insert_tokens(t_token **prev_token, t_token *tokens)
{
	t_token *last_token;

	if (tokens == NULL)
		return ;
	last_token = get_last_token(tokens);
	if (*prev_token == NULL)
		*prev_token = tokens;
	else
	{
		last_token->next = (*prev_token)->next;
		(*prev_token)->next = tokens;
	}
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

t_token	*reverse_token_list(t_token *token)
{
	t_token	*prev_token;
	t_token	*next_token;

	prev_token = NULL;
	while (token != NULL)
	{
		next_token = token->next;
		token->next = prev_token;
		prev_token = token;
		token = next_token;
	}
	return (prev_token);
}
