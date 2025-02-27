/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:32:27 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/27 12:11:48 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-allocator.h"
#include "minishell.h"
#include "../libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "token.h"
#include <stdio.h>
#include <signal.h>

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
int	main(int argc, char**argv, char *envp[])
{
	char	*input;
	t_token *tokens;
	struct sigaction sa;

	//TODO: get env and store it in a static variable
	setup_signal(&sa);
	

	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		tokens = tokenizer(input);
		if (input[0])
			add_history(input);
		while(tokens)
		{
			printf("type: %s, value: %s\n\n", get_token_from_type(tokens->type), tokens->content);
			tokens = tokens->next;
		}
	}
}
