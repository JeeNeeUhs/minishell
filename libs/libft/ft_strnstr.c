/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:41:56 by hsamir            #+#    #+#             */
/*   Updated: 2024/11/02 18:41:56 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static	int	is_match(const char *big, const char *little, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (big[i] && big[i] == little[j] && i < len)
	{
		i++;
		j++;
		if (!little[j])
			return (1);
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!little[0])
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[0] && is_match(big, little, i, len))
			return ((char *)big + i);
		i++;
	}
	return (0);
}
