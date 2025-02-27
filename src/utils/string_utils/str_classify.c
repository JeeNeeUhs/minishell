/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_classify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:08:09 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/27 03:31:49 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	A space or tab character.
*/
int	is_blank(char c)
{
	return (c == ' ' || c == '\t');
}

/*
	A character that, when unquoted, separates words. A metacharacter is a space, tab, newline, or one of the following characters: ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, or ‘>’.
*/
int	is_metacharacter(char c)
{
	return (is_blank(c) || c == '\n' || c == '|' || c == '<' || c == '>');
}

int	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

int is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	is_word_char(char c)
{
	return (c && !is_metacharacter(c) && !is_quote(c));
}
