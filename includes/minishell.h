/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:13:25 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/17 08:30:21 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#define SUCCESS 1
#define FAILURE 0

typedef enum e_token_type
{
	UNQUOTED_WORLD
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	PIPE,
	REDIRECTION_IN,
	REDIRECTION_OUT,
	REDIRECTION_APPEND,
	HEREDOC,
	WHITESPACE
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

#endif
