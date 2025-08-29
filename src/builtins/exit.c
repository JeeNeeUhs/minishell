/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:56:48 by hsamir            #+#    #+#             */
/*   Updated: 2025/08/29 19:10:28 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"
#include "builtins.h"
#include "memory_allocator.h"
#include "minishell.h"
#include <limits.h>

static int	skip_whitespace(const char *c)
{
	int	i;

	i = 0;
	while (c[i] == ' ' || (c[i] >= 9 && c[i] <= 13))
		i++;
	return (i);
}

static int	determine_sign(const char *c, int *i)
{
	int	sign;

	sign = 1;
	if (c[*i] == '-' || c[*i] == '+')
	{
		if (c[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

long	ft_atol(const char *str, int *err)
{
	long	total;
	int		sign;
	int		i;
	int		digit;

	total = 0;
	i = skip_whitespace(str);
	sign = determine_sign(str, &i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		if ((sign == 1 && total > (LONG_MAX - digit) / 10)
			|| (sign == -1 && (unsigned long)total
				> ((unsigned long)LONG_MAX + 1UL - digit) / 10))
		{
			*err = -1;
			return (0);
		}
		total = total * 10 + digit;
		i++;
	}
	i += skip_whitespace(str + i);
	if (str[i] != '\0' || i == 0)
		*err = -1;
	return (sign * total);
}

int	exit_builtin_error_handler(char *arg, int subshell)
{
	if (arg == NULL)
	{
		ft_putstr_fd("hash: exit: too many arguments\n", 2);
		return (1);
	}
	if (!subshell)
		ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("hash: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);;
	return (2);
}

int	exit_builtin(t_command *command)
{
	int		err;
	int		subshell;
	long	exit_code;

	subshell = (command->next || command->prev);
	if (command->args[1] == NULL)
	{
		if (!subshell)
			ft_putstr_fd("exit\n", 2);
		safe_abort(*exit_status());
	}
	err = 0;
	exit_code = ft_atol(command->args[1], &err);
	if (err == -1)
		safe_abort(exit_builtin_error_handler(command->args[1], subshell));
	if (command->args[2] != NULL)
		return (exit_builtin_error_handler(NULL, subshell));
	if (!subshell)
		ft_putstr_fd("exit\n", 2);
	safe_abort(exit_code % 256);
	return (EXECUTION_SUCCESS);
}
