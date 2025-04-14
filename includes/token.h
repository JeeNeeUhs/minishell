/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:07:23 by hsamir            #+#    #+#             */
/*   Updated: 2025/04/14 18:51:26 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

#define QUOTE_ERR "Syntax Error: Unclosed quote detected\n"

#define WORD_MASK (W_UNQUOTED | W_SINGLE_Q | W_DOUBLE_Q)
#define W_QUOTE_MASK (W_SINGLE_Q | W_DOUBLE_Q)
#define REDIR_MASK  (R_IN | R_OUT | R_APPEND | R_HERE)
typedef enum e_token_type
{
	W_UNQUOTED = 1 << 0,
	W_SINGLE_Q = 1 << 1,	//	\'
	W_DOUBLE_Q = 1 << 2,	//	\"
	PIPE = 1 << 3,			//	|
	R_IN = 1 << 4,			//	<
	R_OUT = 1 << 5,			//	>
	R_APPEND = 1 << 6,		//	>>
	R_HERE = 1 << 7,		//	<<
	DELIM = 1 << 8			//	space, tab, newline
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*content;
	struct s_token	*next;
}					t_token;

typedef void		(*t_state)(char *str, int *i, t_token **head_token);

t_token				*get_last_token(t_token *head_token);
t_token				*create_token(t_token new_token);
void				append_token(t_token **head_token, t_token *new_token);
void				remove_token(t_token *prev_token, t_token **token);
void				insert_tokens(t_token *prev_token, t_token **tokens);

t_token_type		get_word_type(char c);
t_token_type		get_operator_type(char *str);
int					is_word_token_type(t_token_type type);
int					is_quoted_word_token_type(t_token_type type);

int					is_valid_quote(char *str);

t_token				*tokenizer(char *str);
t_token				*lexer(char *input);

typedef void		(*t_ifs_state)(char *str, int *i, char *delims, t_token **head_token);
t_token				*field_split(char *str, char *delims);
#endif
