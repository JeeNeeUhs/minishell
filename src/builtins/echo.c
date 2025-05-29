/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:26:51 by ahekinci          #+#    #+#             */
/*   Updated: 2025/05/29 22:30:57 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "command.h"

int	handle_option(char **args, int *display_newline)
{
	char	*temp;
	int		index;

	index = 1;
	*display_newline = 1;
	while (args[index] != NULL)
	{
		temp = args[index];
		if (*temp++ != '-' || *temp != 'n')
			break ;
		while (*temp != '\0' && *temp == 'n')
			temp++;
		if (*temp != '\0')
			break ;
		*display_newline = 0;
		index++;
	}
	return (index);
}

/* source code: https://pastes.dev/pmygsihqWS
Options:
  -n	do not append a newline */
int	echo_builtin(t_command *command)
{
	char	**args;
	int		index;
	int		display_newline;

	args = command->args;
	index = handle_option(args , &display_newline);
	while (args[index])
	{
		ft_putstr_fd(args[index] , command->fd_out);
		if (args[index + 1] != NULL)
			ft_putchar_fd(' ' , command->fd_out);
		index++;
	}
	if (display_newline)
			ft_putchar_fd('\n' , command->fd_out);
	return (EXECUTION_SUCCESS);
}
