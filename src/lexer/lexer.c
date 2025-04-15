/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:02:24 by hsamir            #+#    #+#             */
/*   Updated: 2025/04/14 20:47:16 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "minishell.h"
#include <stddef.h>

t_token	*lexer(char *input)
{
	t_token	*tokens;

	if (is_valid_quote(input))
	{
		print_err("newline", 2);
		return (NULL);
	}
	tokens = tokenizer(input);
	if (!tokens)
		return (NULL);
	/*
		POST_CONDITION {
			=> we have to check heredoc before expanding the tokens
		}
	*/
	return (tokens);
}
