/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:12:28 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/25 11:22:23 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

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
