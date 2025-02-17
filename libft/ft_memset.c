/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:30:18 by hsamir            #+#    #+#             */
/*   Updated: 2024/10/07 18:30:32 by hsamir           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*mem;

	mem = b;
	i = 0;
	while (i < len)
	{
		mem[i++] = (unsigned char)c;
	}
	return (b);
}
