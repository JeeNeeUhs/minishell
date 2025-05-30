/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:32:27 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/30 15:19:31 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_allocator.h"
#include "minishell.h"
#include "command.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "token.h"
#include <stdio.h>
#include "env.h"
#include <unistd.h>
#include <stdlib.h>

/*
https://pastes.dev/YBKlv9bQzq 
*/
int	handle_input(char *input)
{
	t_token		*tokens;
	t_command	*commands;

	if (!validate_quote(input))
		return (report_syntax_error(SYNTAX_ERR));
	tokens = tokenizer(input);
	if (tokens == NULL)
		return (SUCCESS);
	expander(&tokens);
	join_word_tokens(&tokens);
	if (!validate_tokens(tokens))
		return (abort_with_error(tokens, SYNTAX_ERR));
	if (is_max_heredoc_exceeded(tokens))
		return (abort_with_error(tokens, HERE_ERR));
	commands = parse(tokens);
	remove_token_by_flags(&tokens, FLAG_ALL);
	if (!do_heredoc(commands))
		return (SUCCESS);
	if (commands != NULL)
		execute_command(commands);
	return (SUCCESS);
}

int	main(int argc, char**argv, char *envp[])
{
	char	*input;
	char	*prompt_string;

	(void)argc;
	(void)argv;
	init_env(envp);
	if (isatty(STDIN_FILENO))
		init_env((char *[]){PPROMPT, SPROMPT, NULL});
	while (1)
	{
		set_signal_handler(PROMT_SIG);
		prompt_string = expand_prompt_string(get_env_value("PS1"));
		input = readline(prompt_string);
		if (input == NULL)
			break ;
		if (input[0])
		{
			add_history(input);
			handle_input(input);
		}
		free(input);
		safe_free(TEMPORARY);
	}
	safe_abort(*exit_status());
}
