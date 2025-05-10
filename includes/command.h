/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:42:14 by ahekinci          #+#    #+#             */
/*   Updated: 2025/05/08 20:26:12 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H


#define HEREDOC_MAX 16
#define STD_IN 0
#define STD_OUT 1

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
	char					*file_name;		/* EOF or varname to be redirected. */
	int 					flags;			/*Flag value for `open'. */
	t_instruction			instruction;
}							t_redirect;

typedef struct s_command
{
	pid_t 					pid;
	char					**args;			/* The program name, the arguments, 'variable assignments'etc. */
	t_redirect				*redirecs;		/* Redirections to perform. */
	int						fd_in;			/* File descriptor for input. */
	int						fd_out;			/* File descriptor for output. */
	struct					s_command *prev;
	struct					s_command *next;
}							t_command;


t_command				*create_command(t_command new_command);
t_command				*init_command(t_command *prev_command, t_token *token);
t_command				*reverse_command_list(t_command *command);

t_command				*parse(t_token *token);

void					prepend_command(t_command **head_command, t_command *new_command);
void					join_word_parts(t_token **head_token);


void					executor(t_command *command);



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


/*
** example command: cat <<EOF | cat <<EOF"

** args = ["cat"]
** fd_in = 5
** fd_out = 1
** next = pointer to the next command

** args = ["cat"]
** fd_in = 7
** fd_out = 1
** next = pointer to the next command
*/


/*
** if fd_in is equal to 0 it means that the command is reading from the standard input
** if fd_out is equal to 1 it means that the command is writing to the standard output
*/