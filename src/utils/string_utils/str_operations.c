/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:12:28 by hsamir            #+#    #+#             */
/*   Updated: 2025/03/03 21:46:22 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "memory-allocator.h"
#include "minishell.h"
#include  <limits.h>

int	str_equal(char *s1, char *s2)
{
	size_t	s1_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	if (s1_len != ft_strlen(s2))
		return (0);
	return (ft_strncmp(s1, s2, s1_len) == 0);
}

int	find_char_index(char *str, int i, char c)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_blank(str[i]))
		i++;
	return (i);
}

char	*str_arr_join(char	**strings, int count)
{
	char	*new_str;
	int		i;
	int		len;
	int		offset;

	i = 0;
	len = 0;
	while (i < count)
	{
		if (strings[i])
			len += ft_strlen(strings[i]);
		i++;
	}
	if (len == 0)
		return (ft_strdup(""));
	new_str = (char *)safe_talloc(len + 1);
	i = 0;
	offset = 0;
	while (i < count)
	{
		if (strings[i])
			offset += ft_strlcpy(new_str + offset, strings[i], UINT_MAX);
		i++;
	}
	return (new_str);
}
