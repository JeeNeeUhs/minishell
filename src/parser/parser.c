/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:03:35 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/04 07:38:46 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "token.h"
#include "libft.h"
#include <stdbool.h>
#include "libft/libft.h"
#include "stddef.h"

void	argument_state(t_token *token, t_command *command, int *index)
{
	command->args[(*index)++] = ft_strdup(token->content);
}

void	redirection_state(t_token *token, t_command *command, int *index)
{

}

t_command_state get_command_state(t_token_type token_type) //cat <<eof sa <<test << 1 2 3 >1 >2 t a b c
{
	if (token_type & WORD_MASK)
		return (argument_state);
	else if (token_type & REDIR_MASK)
		return (redirection_state);
	return (NULL);
}

t_command	*make_command(t_token *token)
{
	t_command	*command;
	int			index[2];

	ft_memset(index, 0, sizeof(index));
	command = init_command();
	while (token != NULL && token->type != PIPE)
	{
		get_command_state(token->type)(token, command, index[(bool)(token->type & REDIR_MASK)]);
		token = token->next;
	}
	return (command);
}


t_command	*parse(t_token *token)
{
	t_command	*head_command;
	t_command	*command;

	head_command = NULL;
	while (token != NULL)
	{
		command = make_command(token);
		prepend_command(&head_command, command);
		skip_pipe(token);
	}
	return (reverse_command_list(head_command));
}
