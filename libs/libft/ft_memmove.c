/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:50:50 by hsamir            #+#    #+#             */
/*   Updated: 2024/10/18 23:50:51 by hsamir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dst && !src)
		return (0);
	s = (const unsigned char *)src;
	d = (unsigned char *)dst;
	if (d < s)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			d[len] = s[len];
	}
	return (dst);
}
