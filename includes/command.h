/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:42:14 by ahekinci          #+#    #+#             */
/*   Updated: 2025/05/03 13:14:20 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H


#define HEREDOC_MAX 16

#include <token.h>
#include <sys/types.h>

typedef enum e_instruction
{
	I_IN = 1 << 4,			//	<
	I_OUT = 1 << 5,			//	>
	I_APPEND = 1 << 6,		//	>>
	I_HERE = 1 << 7,		//	<<
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
	pid_t 					pid;
	char					**args;			/* The program name, the arguments, 'variable assignments'etc. */
	t_redirect				*redirecs;		/* Redirections to perform. */
	struct					s_command *prev;
	struct					s_command *next;
}							t_command;

t_command				*create_command(t_command new_command);
t_command				*reverse_command_list(t_command *command);
void					prepend_command(t_command **head_command, t_token *new_command);
typedef void			(*t_command_state)(t_token *token, t_command *command);

void					join_word_parts(t_token **head_token);

#endif

/*
** cmd: command name
** args: arguments of the command
** fd_in: file descriptor for input
** fd_out: file descriptor for output
** next: pointer to the next command
*/

/*
** example command: ls -l

** cmd = "ls"
** args = ["ls", "-l"]
** fd_in = 0
** fd_out = 1
** next = NULL
*/

/*
** example command: ls -l | grep "foo"

** cmd = "ls"
** args = ["ls", "-l"]
** fd_in = 0
** fd_out = 1
** next = pointer to the next command

** cmd = "grep"
** args = ["grep", "foo"]
** fd_in = 1
** fd_out = 1
** next = NULL
*/
