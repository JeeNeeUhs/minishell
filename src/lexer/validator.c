/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:46:06 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/11 12:56:05 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"

int	is_valid_quote(char *string)
{
	int		index;

	index = 0;
	while (string[index])
	{
		if (is_quote(string[index]))
		{
			index = find_char_index(string, index + 1, string[index]);
			if (string[index] == '\0')
				return (FAILURE);
		}
		index++;
	}
	return (SUCCESS);
}
