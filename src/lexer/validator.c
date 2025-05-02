/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:46:06 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/02 15:03:51 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"

int	is_valid_quote(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
		{
			i = find_char_index(str, i + 1, str[i]);
			if (!str[i])
				return (1);
		}
		i++;
	}
	return (0);
}
