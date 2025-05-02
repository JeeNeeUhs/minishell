/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:07:40 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/01 20:16:42 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#define HEREDOC_MAX 16

#include <token.h>
#include <sys/types.h>

typedef enum e_instruction
{
	R_IN = 1 << 4,			//	<
	R_OUT = 1 << 5,			//	>
	R_APPEND = 1 << 6,		//	>>
	R_HERE = 1 << 7,		//	<<
}					t_instruction;

/* Instructions describing what kind of thing to do for a redirection. */
typedef struct s_redirect
{
	char					*file_name;		/* Descriptor or varname to be redirected. */
	int 					flags;			/*Flag value for `open'. */
	t_instruction			instruction;
}							t_redirect;

typedef struct s_command
{
	pid_t 				pid;
	char				**args;	/* The program name, the arguments, 'variable assignments'etc. */
	t_redirect			*redirecs; 	/* Redirections to perform. */
	struct				s_command *prev;
	struct				s_command *next;
}						t_command;

typedef void		(*t_command_state)(t_token *token, t_command *command);

void	join_word_parts(t_token *tokens);

#endif
