/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:07:23 by hsamir            #+#    #+#             */
/*   Updated: 2025/03/14 17:16:28 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

#define QUOTE_ERR "Syntax Error: Unclosed quote detected\n"

typedef enum e_token_type
{
	UNQUOTED_WORD,
	SINGLE_QUOTED_WORD, // '
	DOUBLE_QUOTED_WORD, // "
	PIPE,               // |
	REDIRECTION_IN,     // <
	REDIRECTION_OUT,    // >
	REDIRECTION_APPEND, // >>
	HEREDOC,            // <<
	DELIMITER         // space, tab, newline
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*content;
	struct s_token	*next;
}					t_token;

typedef void		(*t_state)(char *str, int *i, t_token **head_token);

t_token				*get_last_token(t_token *head_token);
t_token				*create_token(char *content, t_token_type type);
void				append_token(t_token **head_token, t_token *new_token);
void				remove_token(t_token *prev_token, t_token **token);
void				insert_tokens(t_token *prev_token, t_token **tokens);

t_token_type		get_word_token_type(char c);
t_token_type		get_operator_token_type(char *str);
int					is_word_token_type(t_token_type type);
int					is_quoted_word_token_type(t_token_type type);

int					is_valid_quote(char *str);

t_token				*tokenizer(char *str);
t_token				*lexer(char *input);

typedef void		(*t_ifs_state)(char *str, int *i, char *delims, t_token **head_token);
t_token				*field_split(char *str, char *delims);
#endif
