/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:32:27 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/29 12:53:43 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_allocator.h"
#include "minishell.h"
#include "command.h"
#include "libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "get_next_line.h"
#include "string_utils.h"
#include "token.h"
#include <stdio.h>
#include <signal.h>
#include "env.h"
#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>

#pragma region

const char *token_type_str(t_token_type t)
{
    switch (t) {
    case W_UNQUOTED:  return "W_UNQUOTED";
    case W_SINGLE_Q:  return "W_SINGLE_Q";
    case W_DOUBLE_Q:  return "W_DOUBLE_Q";
    case PIPE:        return "PIPE";
    case R_IN:        return "R_IN";
    case R_OUT:       return "R_OUT";
    case R_APPEND:    return "R_APPEND";
    case R_HERE:      return "R_HERE";
    case DELIM:       return "DELIM";
    case W_INVALID:   return "W_INVALID";
    default:          return "UNKNOWN";
    }
}

void	debug_tokens(t_token *tokens)
{
	printf("\x1b[34m┌──────────────────────────────────────────────────── DEBUG TOKENS ─────────────────────────────────────────────────────┐\x1b[0m\n");
	while(tokens)
	{
        printf("│ \x1b[33m[%11s]\x1b[0m \x1b[32m\"%s\"\x1b[0m\n",
			token_type_str(tokens->type),
			tokens->content ? tokens->content : "(null)");
		tokens = tokens->next;
	}
	printf("\x1b[34m└───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\x1b[0m\n");
}

void	debug_commands(t_command *cmds)
{

	printf("\x1b[34m┌──────────────────────────────────────────────────── DEBUG COMMANDS ────────────────────────────────────────────────────┐\x1b[0m\n");
    for (int i = 0; cmds; cmds = cmds->next, ++i) {
        printf("│ \x1b[33m[%d]\x1b[0m ", i);
        for (char **a = cmds->args; a && *a; ++a)
            printf("- \x1b[32m%s\x1b[0m ", *a);
		for (size_t j = 0; j < cmds->redir_count; j++) {
			t_redirect* r = &cmds->redirecs[j];
			const char *op = r->instruction == I_IN     ? "<"  :
								r->instruction == I_OUT    ? ">"  :
								r->instruction == I_APPEND ? ">>" :
								r->instruction == I_HERE ? "<<" : "?";
			printf("\x1b[31m%s %s \x1b[0m", op, r->file_name);
		}
		printf("\x1b[35min->[%d] out->[%d] \x1b[0m", cmds->fd_in, cmds->fd_out);
        putchar('\n');
    }
	printf("\x1b[34m└────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\x1b[0m\n");

}
#pragma endregion

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
	// debug_tokens(tokens);
	commands = parse(tokens);
	remove_token_by_flags(&tokens, FLAG_ALL);
	if (!do_heredoc(commands))
		return (SUCCESS);
	// debug_commands(commands);
	if (commands != NULL)
		execute_pipeline(commands);
	return (SUCCESS);
}

/*
	READ - EVAL - PRINT - LOOP
*/
int	main(int argc, char**argv, char *envp[])
{
	char	*input;
	char	*prompt_string;

	(void)argc;
	(void)argv;
	init_env(envp);
	if (isatty(STDIN_FILENO))
		init_env((char *[]) {PPROMPT, SPROMPT, NULL});
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
	safe_abort(*exit_status());;
}
