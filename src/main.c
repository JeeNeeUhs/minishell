/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:32:27 by hsamir            #+#    #+#             */
/*   Updated: 2025/04/27 13:55:43 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_allocator.h"
#include "minishell.h"
#include "../libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "parser.h"
#include "token.h"
#include <stdio.h>
#include <signal.h>
#include "env.h"
#include <stdio.h>


/*
	READ - EVAL - PRINT - LOOP
*/
int	main(int argc, char**argv, char *envp[]) // check
{
	char	*input;
	t_token *tokens;
	struct sigaction sa;

	//TODO: get env and store it in a static variable
	if (argc != 1)
	{
		ft_putstr_fd("minishell: no arguments are allowed\n", 2);
		return (1);
	}
	//setup_signal(&sa);
	init_env(envp);

	set_env_value("test", "o\n\nexpander test\n\n");
	// set_env_value("t", "");
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		tokens = lexer(input);
		expander(tokens);
		if (input[0])
			add_history(input);
		join_word_parts(tokens);
		while(tokens)
		{
			if (!(tokens->type & W_INVALID))
				printf("type: %d, value: %s\n\n", tokens->type, tokens->content);
			tokens = tokens->next;
		}
	}
}
