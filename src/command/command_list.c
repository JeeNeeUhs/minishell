/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:53:38 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/02 11:27:07 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "memory_allocator.h"

int get_argument_count(t_token *token)
{
	int	count;

	count = 0;
	while (token != NULL && token->type != PIPE)
	{
		if ((token->type & WORD_MASK) && token->type != W_INVALID) //cat <<eof sa <<test << 1 2 3 >1 >2 t a b c
			count++;
		token = token->next;
	}
	return (count);
}

int get_redirection_count(t_token *token)
{
	int count;

	count = 0;
	while (token != NULL && token->type != PIPE)
	{
		if (token->type & REDIR_MASK)
			count++;
		token = token->next;
	}
	return (count);
}

t_command	*init_command(t_token *token)
{
	t_command	*command;

	command = safe_talloc(sizeof(t_command));
	*command = (t_command){
		.args = safe_talloc (sizeof(char*) * (get_argument_count(token) + 1)),
		.redirection = safe_talloc (sizeof(t_redirection) * (get_redirection_count(token) + 1)),
		.next = NULL,
	};
	return (command);
}

t_token	*reverse_command_list(t_token *token)
{
	t_token	*prev_token;
	t_token	*next_token;

	prev_token = NULL;
	while (token != NULL)
	{
		next_token = token->next;
		token->next = prev_token;
		prev_token = token;
		token = next_token;
	}
	return (prev_token);
}
