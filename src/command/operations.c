/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:29:11 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/02 19:57:25 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "memory_allocator.h"

//cat <<eof sa <<test << 1 2 3 >1 >2 t a b c
int	arg_count(t_token *token)
{
	int	count;
	int	redirect_flag;

	redirect_flag = 0;
	count = 0;
	while (token != NULL && token->type != PIPE)
	{
		if (token->type & W_INVALID)
		{
			token = token->next;
			continue;
		}
		else if ((token->type & WORD_MASK) && !redirect_flag)
			count++;
		else if (token->type & OPERATOR_MASK)
			redirect_flag = 1;
		else
			redirect_flag = 0;
		token = token->next;
	}
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

t_command	*init_command(t_command **head_command, t_token *token)
{
	t_command	*new_command;
	t_command	command;

	command = (t_command){
		.args = safe_talloc(
			sizeof(char*) * (arg_count(token) + 1)),
		.redirecs = safe_talloc(
			sizeof(t_redirect) * (redirect_count(token) + 1)),
		.prev = *head_command,
	};
	new_command = create_command(command);
	prepend_command(head_command, new_command);
	return (new_command);
}
