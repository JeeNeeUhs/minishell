/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:32:27 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/13 22:31:26 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-allocator.h"

#include <stdio.h>
int	str_cpy(char *dest, char *src)
{
	int i;

	i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int	main(int argc, char**arg)
{
	char	*str;

	str = ft_malloc(10);
	str_cpy(str, "Hello");
	printf("%s\n", str);
	ft_abort();
	return (0);
}
