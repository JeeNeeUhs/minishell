/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:03:35 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/06 20:27:46 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "token.h"
#include "libft.h"
#include <stdbool.h>
#include "stddef.h"

t_token	*make_command(t_token *token, t_command *command)
{
	int	arg_index;
	int	redir_index;

	arg_index = 0;
	redir_index = 0;
	while (token != NULL && token->type != PIPE)
	{
		if (token->type & WORD_MASK)
			command->args[arg_index++] = ft_strdup(token->content);
		else
		{
			command->redirecs[redir_index++] = (t_redirect){
				.instruction = (t_instruction)token->type,
				.file_name = ft_strdup(token->next->content),
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
