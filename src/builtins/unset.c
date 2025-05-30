/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 23:22:41 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/30 22:47:58 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "env.h"

int	unset_builtin(t_command *command)
{
	int	index;

	index = 1;
	while (command->args[index])
	{
		remove_env(command->args[index]);
		index++;
	}
	return (EXECUTION_SUCCESS);
}
