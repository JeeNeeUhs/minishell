/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:42:14 by ahekinci          #+#    #+#             */
/*   Updated: 2025/03/19 16:12:13 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

typedef struct s_command {
	char				*cmd;
	char				**args;
	int					fd_in;
	int					fd_out;
	struct  s_command	*next;
}				t_command;

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
