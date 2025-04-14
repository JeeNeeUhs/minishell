/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:00:16 by hsamir            #+#    #+#             */
/*   Updated: 2025/04/13 20:45:29 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token_type	get_operator_type(char *str)
{
	if (str[0] == '>')
	{
		if (str[1] == '>')
			return (R_APPEND);
		else
			return (R_OUT);
	}
	else if (str[0] == '<')
	{
		if (str[1] == '<')
			return (R_HERE);
		else
			return (R_IN);
	}
	else
		return (PIPE);
}

t_token_type	get_word_type(char c)
{
	if (c == '\"')
		return (W_DOUBLE_Q);
	else if (c == '\'')
		return (W_SINGLE_Q);
	else
		return (W_UNQUOTED);
}

// int	is_word_token_type(t_token_type type)
// {
// 	return (type == UNQUOWORD || type == DOUBLE_QUOTED_WORD
// 		|| type == SINGLE_QUOTED_WORD);
// }

// int	is_quoted_word_token_type(t_token_type type)
// {
// 	return (type == SINGLE_QUOTED_WORD || type == DOUBLE_QUOTED_WORD);
// }
