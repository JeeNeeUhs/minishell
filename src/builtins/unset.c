/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 23:22:41 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/21 11:18:37 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "env.h"

/* Unsetting a variable or function that was not previously set shall
     not be considered an error and does not cause the shell to abort.*/
void	unset_builtin(t_command *command)
{
	int	index;

	index = 1;
	while (command->args[index])
	{
		remove_env(command->args[index]);
		index++;
	}
}
