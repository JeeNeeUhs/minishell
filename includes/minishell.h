/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:13:25 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/15 18:21:54 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# define SUCCESS 1
# define FAILURE 0

# define SHELL_NAME "hash"

# define DEFAULT_IFS " \t\n"

# define PPROMPT "\e[31m\\u@\e[0m\e[34m~\\w:\\s\e[0m$ "
# define SPROMPT "\033[31m>\033[0m "
# define ESC_CHR "shawue"

# include <stddef.h>
# include <signal.h>

//Patterns
int		is_quote(char c);
int		is_operator(char c);
int		is_metacharacter(char c);
int		is_blank(char c);
int		is_word_char(char c);
int		is_var_char(char c);
int		is_var_start(char *input);

int		replace_with_expansion(char **input, int index, char *rep, int offset);

int		safe_exit(int status, char *message);
int		report_syntax_error(char *message);
int		*exit_status(void);

//Prompt
char	*expand_prompt_string(char *input);

//signal
void	setup_signal(struct sigaction *sa);
#endif
