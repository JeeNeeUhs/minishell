/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:26:12 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/19 22:53:52 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include "memory_allocator.h"
#include <limits.h>

int	sequential_tokens_len(t_token *token, int flags)
{
	int	len;

	len = 0;
	while (token != NULL && token->type & flags)
	{
		len += ft_strlen(token->content);
		token = token->next;
	}
	return (len);
}

t_token	*join_sequential_tokens(t_token *base_token, int flags)
{
	char	*new_str;
	size_t	len;
	int		offset;
	int		merged_flag;
	t_token	*token;

	if (base_token->next == NULL || base_token->next->type & ~flags) //TEST ET
		return (base_token->next);
	offset = 0;
	merged_flag = 0;
	len = sequential_tokens_len(base_token, flags);
	new_str = (char *)safe_talloc(len + 1);
	token = base_token;
	while (token != NULL && token->type & flags)
	{
		offset += ft_strlcpy(new_str + offset, token->content, UINT_MAX);
		merged_flag |= token->type;
		token->type = W_INVALID;
		token = token->next;
	}
	safe_free_ptr(base_token->content, TEMPORARY);
	base_token->content = new_str;
	base_token->type = merged_flag;
	return (token);
}

void	join_word_tokens(t_token **head_token)
{
	t_token	*token;

	token = *head_token;
	while (token != NULL)
	{
		if (token->type & WORD_MASK)
			token = join_sequential_tokens(token, WORD_MASK);
		else
			token = token->next;
	}
	remove_token_by_flags(head_token, W_INVALID | DELIM);
}
