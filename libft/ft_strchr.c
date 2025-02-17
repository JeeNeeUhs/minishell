/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:10:36 by hsamir            #+#    #+#             */
/*   Updated: 2024/10/07 21:10:37 by hsamir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	i = ft_strlen(s);
	j = 0;
	while (i >= 0)
	{
		if (s[j] == (char)c)
			return ((char *)s + j);
		i--;
		j++;
	}
	return (0);
}
