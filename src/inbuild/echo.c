/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:26:51 by ahekinci          #+#    #+#             */
/*   Updated: 2025/03/02 16:55:41 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	echo(char flag, char **params)
{
	int	i;

	i = 0;
	if (flag == 'n')
	{
		while (params[++i])
		{
			printf("%s", params[i]);
			if (params[i + 1])
				printf(" ");
		}
	}
	else
	{
		while (params[++i])
		{
			printf("%s", params[i]);
			if (params[i + 1])
					printf(" ");
		}
		printf("\n");
	}
	return (0);
}
