/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:03:35 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/04 13:43:02 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "token.h"
#include "libft.h"
#include <stdbool.h>
#include "libft/libft.h"
#include "stddef.h"

void	make_command(t_token **root_token, t_command *command)
{
	t_token		*token;
	int			index[2];

	ft_memset(index, 0, sizeof(index));
	token = *root_token; 
	while (token != NULL && token->type != PIPE)
	{
		if (token->type & WORD_MASK)
			command->args[index[0]++] = ft_strdup(token->content);
		else
		{
			command->redirecs[index[1]++] = (t_redirect){
				.instruction = token->type,
				.file_name = ft_strdup(token->next->content),
			};
			token = token->next;
		}
		token = token->next;
	}
	*root_token = token;
	return (command);
}

t_command	*parse(t_token *token)
{
	t_command	*head_command;
	t_command	*command;

	head_command = NULL;
	while (token != NULL)
	{
		command = init_command(head_command, token);
		make_command(&token, command);
		prepend_command(&head_command, command);
	}
	return (reverse_command_list(head_command));
}
