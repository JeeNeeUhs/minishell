/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:18:32 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/21 19:10:36 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include "libft.h"
#include "command.h"

int	report_export_error(char* variable)
{
	ft_putstr_fd("hash: export: `", 2);
	ft_putstr_fd(variable, 2);
	ft_putstr_fd("`: not a valid identifier\n", 2);
	*exit_status() = 1;
	return (EXECUTION_FAILURE);
}
