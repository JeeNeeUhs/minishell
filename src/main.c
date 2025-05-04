/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:32:27 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/04 14:39:48 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_allocator.h"
#include "minishell.h"
#include "command.h"
#include "../libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "token.h"
#include <stdio.h>
#include <signal.h>
#include "env.h"
#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
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
		if (input[0])
			add_history(input);
		tokens = lexer(input);
		expander(&tokens);
		join_word_tokens(&tokens);
		t_command* commands = parse(tokens);
		while(tokens)
		{
			printf("type: %d, value: %s\n\n", tokens->type, tokens->content);
			tokens = tokens->next;
		}
		// while (commands)
		// {
			
		// 	while(*commands->args != NULL)
		// 		printf("arg: %s\n", *commands->args++);
		// 	printf ("--------------\n");
		// 	// while(commands->redirecs)
		// 	// {
		// 	// 	printf("redir name:%s , :%d\n", commands->redirecs->file_name, commands->redirecs->instruction);
		// 	// 	commands->redirecs++;
		// 	// }
		// 	commands = commands->next;
		// }
	}
}
