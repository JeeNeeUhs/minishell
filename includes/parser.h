/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:07:40 by hsamir            #+#    #+#             */
/*   Updated: 2025/04/22 21:30:20 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#define HEREDOC_MAX 16

typedef struct s_redirection
{
	int type;
	char *file;
	struct s_redirection *next;
}	t_redirection;

typedef struct s_command
{
	char **args;
	t_redirection redirection;
	struct s_command *next;
	struct s_command *prev;
}	t_command;

typedef enum e_redirection_type
{
	PIPE = 1 << 3,			//	|
	R_IN = 1 << 4,			//	<
	R_OUT = 1 << 5,			//	>
	R_APPEND = 1 << 6,		//	>>
	R_HERE = 1 << 7,		//	<<
}	t_redirection_type;

#endif

