/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:47:33 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/30 12:36:42 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"
#include "minishell.h"

int	*exit_status(void)
{
	static int	exit_status = 0;

	return (&exit_status);
}

void	set_exit_status(int status)
{
	*exit_status() = status;
}

int	report_syntax_error(char *message)
{
	if (message != NULL)
		ft_putstr_fd(message, 2);
	set_exit_status(2);
	return (FAILURE);
}

int	abort_with_error(t_token *tokens, char *message)
{
	report_syntax_error(message);
	remove_token_by_flags(&tokens, FLAG_ALL);
	return (FAILURE);
}
