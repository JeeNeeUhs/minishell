/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:19:57 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/22 17:59:46 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/*
	A space or tab character.
*/
int is_blank(char c)
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

int	skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_blank(str[i]))
		i++;
	return (i);
}

int find_char_index(char *str, int i, char c)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
