/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:46:06 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/27 04:16:52 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"

int	is_valid_quote(char *str)
{
	char	last_quote;
	int		i;

	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
		{
			i = find_char_index(str, i, str[i]);
			if (!str[i])
				return (1);
		}
		else
			i++;
	}
	return (0);
}

