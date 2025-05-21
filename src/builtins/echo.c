/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:26:51 by ahekinci          #+#    #+#             */
/*   Updated: 2025/05/21 11:18:19 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "command.h"

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

void	echo_builtin(t_command *command)
{

}
