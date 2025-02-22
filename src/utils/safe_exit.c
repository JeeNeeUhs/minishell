/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:46:12 by hsamir            #+#    #+#             */
/*   Updated: 2025/02/22 10:32:22 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-allocator.h"

int safe_exit(int status, char *message)
{
	if (message)
		ft_putstr_fd(message, 2);
	ft_free_all();
	exit(status);
}
