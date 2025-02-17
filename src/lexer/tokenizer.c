/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:32:31 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/17 14:28:08 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-allocator.h"
#include "minishell.h"
#include "../libft/libft.h"

t_token	*create_token(void);

int	is_metacharacter(char c)
{
	return (c == WORLD || c == SINGLE_QUOTE || c == DOUBLE_QUOTE || c == COMMAND
		|| c == OPERATOR);
}
t_token	*tokenizer(char *str)
{
	t_token	*tokens;
	int		i;
	int		quote_type;

	tokens = NULL;
	i = 0;
	while (str[i])
	{
		
	}
}
