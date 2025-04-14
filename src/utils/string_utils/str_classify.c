/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_classify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:08:09 by hsamir            #+#    #+#             */
/*   Updated: 2025/04/14 16:11:23 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	A space or tab character.
*/
int	is_blank(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/*
	A character that, when unquoted, separates words. A metacharacter is a space, tab, newline, or one of the following characters: ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, or ‘>’.
*/
int	is_metacharacter(char c)
{
	return (is_blank(c) || c == '|' || c == '<' || c == '>');
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

int is_var_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}
