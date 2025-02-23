/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:00:16 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/23 12:34:36 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token_type	get_operator_type(char *str)
{
	if (str[0] == '>')
	{
		if (str[1] == '>')
			return (REDIRECTION_APPEND);
		else
			return (REDIRECTION_OUT);
	}
	else if (str[0] == '<')
	{
		if (str[1] == '<')
			return (HEREDOC);
		else
			return (REDIRECTION_IN);
	}
	else
		return (PIPE);
}

t_token_type	get_word_type(char c)
{
	if (c == '\"')
		return (DOUBLE_QUOTED_WORD);
	else if (c == '\'')
		return (SINGLE_QUOTED_WORD);
	else
		return (UNQUOTED_WORD);
}

int	is_word_token(t_token_type type)
{
	return (type == UNQUOTED_WORD || type == DOUBLE_QUOTED_WORD
		|| type == SINGLE_QUOTED_WORD);
}
