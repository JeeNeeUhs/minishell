/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:02:24 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/11 14:16:22 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "minishell.h"
#include <stddef.h>

t_token	*lexer(char *input)
{
	t_token	*tokens;

	if (!is_valid_quote(input))
		return (print_syntax_error(SYNTAX_ERR));
	tokens = tokenizer(input);
	if (tokens == NULL)
		return (NULL);
	if (is_max_heredoc_exceeded(tokens))
	{
		print_syntax_error(HERE_ERR);
		remove_token_by_flags(&tokens, FLAG_ALL);
	}
	return (tokens);
}
