/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:02:24 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/23 13:04:39 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stddef.h>

t_token	*lexer(char *input)
{
	t_token	*tokens;

	if (syntax_check(input))
		return (NULL);
	tokens = tokenizer(input);
	if (!tokens)
		return (NULL);
	if (!check_tokens_syntax(tokens))
	{
		free_tokens(tokens);
		return (NULL);
	}
	return (tokens);
}
