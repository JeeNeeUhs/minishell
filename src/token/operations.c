/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:26:19 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/14 10:27:53 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stddef.h>

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

void	insert_tokens(t_token **prev_token, t_token *tokens)
{
	t_token	*last_token;

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
