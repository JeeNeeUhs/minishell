/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 08:59:01 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/09 19:32:55 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <fcntl.h>

int	get_flags(t_instruction instruction)
{
	int	flags;

	flags = 0;
	if (instruction & I_APPEND)
		flags = O_APPEND | O_CREAT | O_WRONLY;
	else if (instruction & I_OUT)
		flags = O_TRUNC | O_CREAT | O_WRONLY;
	else if (instruction & I_IN)
		flags = O_RDONLY;
	else if (instruction & I_HERE)
		flags = O_CREAT | O_TRUNC | O_RDWR;
	return (flags);
}

int	open_redir_file(t_redirect *redirecs)
{
	int	flags;


}

int	do_redirections(t_redirect *redirecs)
{

}

void	make_redirection(t_redirect *redirecs)
{
	int flags;

	flags = set_flags(redirecs);
}


