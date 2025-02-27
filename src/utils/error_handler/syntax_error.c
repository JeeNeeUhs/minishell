/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:29:47 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/27 16:43:35 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*get_exit_status_var(void)
{
	static int	exit_status_var = 0;

	return (&exit_status_var);
}

void	print_quote_err()
{
	*get_exit_status_var() = 2;
}
