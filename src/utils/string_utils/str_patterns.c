/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_patterns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:34:32 by ahekinci          #+#    #+#             */
/*   Updated: 2025/05/30 12:35:28 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_blank(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	is_metacharacter(char c)
{
	return (is_blank(c) || c == '|' || c == '<' || c == '>');
}

int	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	is_word_char(char c)
{
	return (c && !is_metacharacter(c) && !is_quote(c));
}
