/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:53:38 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/21 17:41:37 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "memory_allocator.h"

t_command	*create_command(t_command new_command)
{
	t_command	*command;

	command = safe_talloc(sizeof(new_command));
	if (!command)
		return (NULL);
	*command = new_command;
	return (command);
}

void	prepend_command(t_command **head_command, t_command *new_command)
{
	if (*head_command == NULL)
		*head_command = new_command;
	else
	{
		new_command->next = *head_command;
		*head_command = new_command;
	}
}

t_command	*reverse_command_list(t_command *command)
{
	t_command	*prev_command;
	t_command	*next_command;

	prev_command = NULL;
	while (command != NULL)
	{
		next_command = command->next;
		command->next = prev_command;
		command->prev = next_command;
		prev_command = command;
		command = next_command;
	}
	return (prev_command);
}
