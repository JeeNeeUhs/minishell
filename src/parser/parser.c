/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:03:35 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/14 15:23:39 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "token.h"
#include "libft.h"

t_token	*make_command(t_token *token, t_command *command)
{
	char		**args;
	t_redirect	*redir;

	redir = command->redirecs;
	args = command->args;
	while (token != NULL && token->type != PIPE)
	{
		if (token->type & WORD_MASK)
			*args++ = ft_strdup(token->content);
		else
		{
			*redir++ = (t_redirect){
				.instruction = token->type & REDIR_MASK,
				.flags = token->next->type & WORD_MASK,
				.file_name = ft_strdup(token->next->content)
			};
			token = token->next;
		}
		token = token->next;
	}
	if (token != NULL)
		token = token->next;
	return (token);
}

t_command	*parse(t_token *token)
{
	t_command	*head_command;
	t_command	*command;

	head_command = NULL;
	while (token != NULL)
	{
		command = init_command(head_command, token);
		prepend_command(&head_command, command);
		token = make_command(token, command);
	}
	return (reverse_command_list(head_command));
}
