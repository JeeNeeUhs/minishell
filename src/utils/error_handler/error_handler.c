/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:47:33 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/11 16:01:25 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"
#include <stdlib.h>

int	*get_exit_status(void)
{
	static int	exit_status = 0;

	return (&exit_status);
}

void	*report_syntax_error(char* message)
{
	if (message != NULL)
		ft_putstr_fd(message, 2);
	*get_exit_status() = 2;
	return (NULL);
}

int	safe_exit(int status, char *message)
{
	if (message)
		ft_putstr_fd(message, 2);
	exit(status);
}
/*
	cat > $files -> bash: $files: ambiguous redirect
	not_exist_command -> not_exist_command: command not found
	cat <file.txt -> bash: file.txt: Permission denied
	 echo <<1 <<2 <<3 <<4 <<5 <<6 <<7 <<8 <<9 <<10 || <<11 <<12 <<13 <<14 <<15 <<16 <<17 -> bash: maximum here-document count exceeded
	 cat > syntax error near unexpected token 'newline'

*/
