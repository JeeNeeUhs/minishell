/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:13:25 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/22 10:44:09 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#define SUCCESS 1
#define FAILURE 0

typedef enum e_token_type
{
	UNQUOTED_WORD,
	SINGLE_QUOTED_WORD, // '
	DOUBLE_QUOTED_WORD, // "
	PIPE, // |
	REDIRECTION_IN, // <
	REDIRECTION_OUT, // >
	REDIRECTION_APPEND, // >>
	HEREDOC, // <<
	DELIMINETER // space, tab, newline
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*content;
	struct	s_token	*next;
}	t_token;

typedef struct s_quote
{
	t_token_type	quote_type;
	struct	s_quote	*next;
}	t_quote;

typedef 	void	(*t_state) (char* str, int* i, t_token **head_token);

int skip_whitespace(char *str);
int	is_quote(char c);
int is_operator(char c);
int	is_metacharacter(char c);
int is_blank(char c);

t_token	*get_last_token(t_token *head_token);
t_token	*create_token(t_token**	head_token, char* content, t_token_type type);

int safe_exit(int status, char *message);

int find_char_index(char str, int start_index, char c);
#endif
