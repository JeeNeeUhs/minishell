/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:29:47 by hsamir            #+#    #+#             */
/*   Updated: 2025/04/14 20:53:30 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "token.h"

int	*get_exit_status(void)
{
	static int	exit_status = 0;

	return (&exit_status);
}

void	print_err(char* message, int exit_status)
{
	if (message)
		printf(SYNTAX_ERR, message);
	*get_exit_status() = 2;
}

/*
	cat > $files -> bash: $files: ambiguous redirect
	not_exist_command -> not_exist_command: command not found
	cat <file.txt -> bash: file.txt: Permission denied
	 echo <<1 <<2 <<3 <<4 <<5 <<6 <<7 <<8 <<9 <<10 || <<11 <<12 <<13 <<14 <<15 <<16 <<17 -> bash: maximum here-document count exceeded
	 cat > syntax error near unexpected token 'newline'
	 
*/
