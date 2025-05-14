/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:40:44 by hsamir            #+#    #+#             */
/*   Updated: 2024/11/02 18:40:44 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../includes/memory_allocator.h"

static int	letter_count(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			i += letter_count(s + i, c);
		}
		else
			i++;
	}
	return (count);
}

static char	**free_arr(char **arr, int i)
{
	while (i >= 0)
	{
		safe_free_ptr(arr[i], TEMPORARY);
		i--;
	}
	safe_free_ptr(arr, TEMPORARY);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	if (!s)
		return (0);
	arr = (char **)safe_talloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!arr)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			arr[i] = ft_substr(s, 0, letter_count(s, c));
			if (!arr[i])
				return (free_arr(arr, i - 1));
			s += letter_count(s, c);
			i++;
		}
	}
	arr[i] = 0;
	return (arr);
}
