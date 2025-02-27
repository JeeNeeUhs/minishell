/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:29:47 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/27 21:52:30 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*get_exit_status(void)
{
	static int	exit_status = 0;

	return (&exit_status);
}

void	print_err(char* message, int exit_status)
{
	if (message)
		ft_putstr_fd(message, 2);
	*get_exit_status() = 2;
}
