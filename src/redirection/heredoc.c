/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:52:03 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/11 21:07:26 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "minishell.h"
#include "env.h"
#include <stdlib.h>
#include "libft.h"
#include <readline/readline.h>
#include <memory_allocator.h>
#include <string.h>
#include <unistd.h>

int	here_document_to_fd(t_redirect *redir)
{
	int	here_pipe[2];
	int	document_len;
	int	written;

	if(pipe(here_pipe) == -1)
	{
		perror("pipe");
		return (-1);
	}
	if (redir->flags & W_DOUBLE_Q)
		expand_string(&redir->document);
	document_len = strlen(redir->document);
	written = write(here_pipe[1], redir->document, document_len);
	close(here_pipe[1]);
	if (written == -1)
	{
		perror("write");
		close(here_pipe[0]);
		return (-1);
	}
	return (here_pipe[1]);
}

int	make_here_document(t_redirect *redir)
{
	char*	prompt_string;
	char*	temp;
	char*	input;
	char*	document;

	document = ft_strdup("");
	prompt_string = expand_prompt_string(get_env_value("PS2"));
	while (1)
	{
		input = readline(prompt_string);
		if (input == NULL || str_equal(input, redir->file_name))
			break;
		temp = document;
		document = str_arr_join((char*[]){document, "\n", input}, 3);
		safe_free_ptr(temp, TEMPORARY);
		free(input);
	}
	redir->document = document;
	safe_free_ptr(prompt_string, TEMPORARY);
	return (here_document_to_fd(redir));
}
