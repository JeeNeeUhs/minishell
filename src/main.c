/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:32:27 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/22 18:12:35 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-allocator.h"
#include "minishell.h"
#include "../libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "token.h"
#include <stdio.h>

char *get_token_from_type(t_token_type type)
{
	if (type == UNQUOTED_WORD)
		return ("UNQUOTED_WORD");
	if (type == SINGLE_QUOTED_WORD)
		return ("SINGLE_QUOTED_WORD");
	if (type == DOUBLE_QUOTED_WORD)
		return ("DOUBLE_QUOTED_WORD");
	if (type == PIPE)
		return ("PIPE");
	if (type == REDIRECTION_IN)
		return ("REDIRECTION_IN");
	if (type == REDIRECTION_OUT)
		return ("REDIRECTION_OUT");
	if (type == REDIRECTION_APPEND)
		return ("REDIRECTION_APPEND");
	if (type == HEREDOC)
		return ("HEREDOC");
	return ("DELIMINETER");
}

/*
	READ - EVAL - PRINT - LOOP
*/
int	main(int argc, char**argv)
{
	char	*input;
	t_token *tokens;

	argv[0] = NULL;
	if (argc != 1)
	{
		ft_putstr_fd("minishell: no arguments needed\n", 2);
		return (1);
	}
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		tokens = tokenizer(input);
		while(tokens)
		{
			printf("type: %s, value: %s\n", get_token_from_type(tokens->type), tokens->content);
			tokens = tokens->next;
		}
		//T
	}
}
