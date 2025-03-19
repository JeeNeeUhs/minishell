/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:05:34 by hsamir            #+#    #+#             */
/*   Updated: 2025/03/14 17:51:29 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_allocator.h"
#include "libft.h"

static int	letter_count(char *s, char *delim)
{
	int	i;

	i = 0;
	while (s[i] && !ft_strchr(delim, s[i]))
		i++;
	return (i);
}

int	word_count(const char *s, char* delim)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_strchr(delim, s[i]))
		{
			count++;
			i += letter_count(s + i, delim);
		}
		else
			i++;
	}
	return (count);
}

char	**split_by_delims(char *str, char *delim)
{
	char	**arr;
	int		i;

	if (!str || !delim)
		return (0);
	arr = (char **)safe_talloc(sizeof(char *) * (word_count(str, delim) + 1));
	i = 0;
	while (*str)
	{
		if (ft_strchr(delim, *str))
			str++;
		else
		{
			arr[i] = ft_substr(str, 0, letter_count(str, delim));
			str += letter_count(str, delim);
			i++;
		}
	}
	arr[i] = 0;
	return (arr);
}
