/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:08:10 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/27 00:18:34 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-allocator.h"
#include "token.h"

t_token	*create_token(char* content, t_token_type type)
{
	t_token	*token;

	token = safe_talloc(sizeof(t_token));
	if (!token)
		return (NULL);
	*token = (t_token){.content = content, .type = type, .next = NULL};
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
	if (*head_token == NULL)
		*head_token = new_token;
	else
		get_last_token(*head_token)->next = new_token;
}
