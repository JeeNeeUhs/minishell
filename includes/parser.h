/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:07:40 by hsamir            #+#    #+#             */
/*   Updated: 2025/04/23 08:54:33 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#define HEREDOC_MAX 16

typedef struct s_redirection
{

	char *file;
	int flags;
	t_instruction instruction;
	struct s_redirection *next;
}	t_redirection;

typedef struct s_command
{
	char **args;	/* The program name, the arguments, 'variable assignments', etc. */
	t_redirection redirection; 	/* Redirections to perform. */
	struct s_command *prev;
	struct s_command *next;
}	t_command;

typedef enum e_instruction
{
	PIPE = 1 << 3,			//	|
	R_IN = 1 << 4,			//	<
	R_OUT = 1 << 5,			//	>
	R_APPEND = 1 << 6,		//	>>
	R_HERE = 1 << 7,		//	<<
}	t_instruction;

#endif

