/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:42:14 by ahekinci          #+#    #+#             */
/*   Updated: 2025/09/02 16:27:11 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# define STD_IN 0
# define STD_OUT 1
# define FD_IN 144
# define FD_OUT 96

# include <sys/types.h>
# include <token.h>

# define EX_NOEXEC 126
# define EX_NOTFOUND 127
# define EXECUTION_FAILURE 1
# define EXECUTION_SUCCESS 0

typedef enum e_instruction
{
	I_IN = 1 << 4,
	I_OUT = 1 << 5,
	I_APPEND = 1 << 6,
	I_HERE = 1 << 7,
}						t_instruction;

typedef struct s_redirect
{
	char				*file_name;
	int					flags;
	char				*document;
	t_instruction		instruction;
}						t_redirect;

typedef struct s_command
{
	char				**args;
	t_redirect			*redirecs;
	size_t				redir_count;
	int					fd_in;
	int					fd_out;
	struct s_command	*prev;
	struct s_command	*next;
}						t_command;

t_command				*create_command(t_command new_command);
t_command				*init_command(t_command *prev_command, t_token *token);
t_command				*reverse_command_list(t_command *command);

t_command				*parse(t_token *token);

void					prepend_command(t_command **head_command,
							t_command *new_command);
void					join_word_parts(t_token **head_token);

int						do_redirection(t_command *command);
int						do_heredoc(t_command *command);
int						set_std_fds(t_command *command);

int						here_document_to_fd(t_redirect *redir);

int						make_pipe(t_command *command);
void					close_fds(t_command *command);
void					fini_func(void *params);

int						need_subshell(t_command *command);
pid_t					make_subshell(t_command *command);
pid_t					make_child(void);
void					wait_children(pid_t last_pid);

char					*search_command_path(char *command);

void					execute_command(t_command *command);
void					execute_pipeline(t_command *command);
int						execute_builtin(t_command *command);
int						execute_disk_command(t_command *command);

void					command_not_found(char *command);
void					abort_command(char *command, int status);
void					print_pipeline(int exit_code);

void					determinate_signal_handler(t_command *command);
#endif
