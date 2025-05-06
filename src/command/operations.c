/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:29:11 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/06 20:44:58 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "memory_allocator.h"
#include "stdio.h"

int	arg_count(t_token *token)
{
	t_token_type	prev_type;
	int				count;

	prev_type = WORD_MASK;
	count = 0;
	while (token != NULL && token->type != PIPE)
	{
		if (token->type & WORD_MASK && prev_type & ~REDIR_MASK)
			count++;
		prev_type = token->type;
		token = token->next;
	}
	printf("count: %d\n", count);
	return (count);
}

int	redirect_count(t_token *token)
{
	int	count;

	count = 0;
	while (token != NULL && token->type != PIPE)
	{
		if (token->type & REDIR_MASK)
			count++;
		token = token->next;
	}
	return (count);
}

t_command	*init_command(t_command *prev_command, t_token *token)
{
	t_command	command;
	int			redir_len;
	int			arg_len;

	redir_len = redirect_count(token);
	arg_len = arg_count(token);
	command = (t_command){
		.args = safe_talloc(sizeof(char*) * (arg_len + 1)),
		.redirecs = safe_talloc(sizeof(t_redirect) * (redir_len)),
		.prev = prev_command,
		.next = NULL
	};
	command.args[arg_len] = NULL;
	return (create_command(command));
}
