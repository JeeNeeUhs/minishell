/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:55:09 by hsamir            #+#    #+#             */
/*   Updated: 2024/11/02 16:55:09 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_first_position(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr(set, str[i]))
		i++;
	return (i);
}

static int	get_last_position(char const *str, char const *set)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i > 0 && str[i] && ft_strchr(set, str[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (!s1 || !set)
		return (0);
	start = get_first_position(s1, set);
	end = get_last_position(s1, set);
	if (start > end)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}
