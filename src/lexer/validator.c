/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:46:06 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/25 16:03:07 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"

int check_input_syntax(char* input);

// if operator token is first or last token, it will be syntax error
// if operator token is followed by another operator token, it will be syntax error
int check_tokens_syntax(t_token *token);


int	quote_check(char *str)
{
	char	quote;
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			quote = str[i];
			i++;
			while (str[i] && str[i] != quote)
				i++;
			if (!str[i])
				return (1);
		}
		i++;
	}
	return (0);
}

