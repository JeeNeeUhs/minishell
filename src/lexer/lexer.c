/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:02:24 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/27 04:06:44 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stddef.h>

t_token	*lexer(char *input)
{
	t_token	*tokens;

	if (is_valid_quote(input))
		return (NULL); //todo i have to prompt syntax error
	tokens = tokenizer(input);
	if (!tokens)
		return (NULL);
	//todo i have to ensure that maybe i can check post condition
	return (tokens);
}
