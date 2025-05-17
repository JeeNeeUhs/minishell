/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:07:23 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/15 14:43:24 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define HEREDOC_MAX 16
# define SYNTAX_ERR "hash: syntax error near unexpected token\n"
# define HERE_ERR "hash: maximum here-document count exceeded\n"

# define WORD_MASK 7			/*(W_UNQUOTED | W_SINGLE_Q | W_DOUBLE_Q)*/
# define W_QUOTE_MASK 6			/*(W_SINGLE_Q | W_DOUBLE_Q)*/
# define REDIR_MASK 240			/*(R_IN | R_OUT | R_APPEND | R_HERE)*/
# define OPERATOR_MASK 248		/*(PIPE | REDIR_MASK)*/
# define META_MASK 504			/*(OPERATOR_MASK | DELIM)*/
# define FLAG_ALL -1

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
	DELIM = 1 << 8,			//	space, tab, newline
	W_INVALID = 1 << 9
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
t_token				*reverse_token_list(t_token *token);

void				prepend_token(t_token **head_token, t_token *new_token);
void				remove_token(t_token **head, t_token *prev, t_token *token);
void				remove_token_by_flags(t_token **head_token, int flags);
void				insert_tokens(t_token **prev_token, t_token *tokens);

t_token_type		get_word_type(char c);
t_token_type		get_operator_type(char *str);

//validator
int					validate_quote(char *str);
int					is_max_heredoc_exceeded(t_token *token);
int					validate_tokens(t_token *tokens);
int					abort_with_error(t_token *token, char *message);

//lexer
t_token				*tokenizer(char *str);

//expander
void				expander(t_token **head_token);
void				expand_string(char **input);
void				word_split(t_token *token);

//token merging
void				join_word_tokens(t_token **head_token);

#endif
