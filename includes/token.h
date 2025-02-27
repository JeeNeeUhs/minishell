/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:07:23 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/27 04:11:00 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

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

typedef 	void	(*t_state) (char* str, int* i, t_token **head_token);

t_token			*get_last_token(t_token *head_token);
t_token			*create_token(char* content, t_token_type type);
void			append_token(t_token **head_token, t_token *new_token);

t_token_type	get_word_token_type(char c);
t_token_type	get_operator_token_type(char *str);
int				is_word_token_type(t_token_type type);
int				is_quoted_word_token_type(t_token_type type);

int				is_valid_quote(char *str);


t_token			*tokenizer(char *str);
t_token			*lexer(char *input);


#endif
