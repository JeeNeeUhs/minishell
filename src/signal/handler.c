/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:10:33 by hsamir            #+#    #+#             */
/*   Updated: 2025/05/29 22:48:42 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"

void	handle_sigquit(int sig)
{
	g_signal = sig;
	printf("Quit (core dumped)\n");
	rl_replace_line("", 0);
	set_exit_status(128 + sig);
}

void	handle_sigint_here(int sig)
{
	g_signal = sig;
	rl_replace_line("", 0);
	rl_done = 1;
	set_exit_status(128 + sig);
}

void	handle_sigint_exec(int sig)
{
	g_signal = sig;
	printf("\n");
	set_exit_status(128 + sig);
}

void	handle_sigint_prompt(int sig)
{
	g_signal = sig;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	set_exit_status(128 + sig);
}

int	do_noop(void)
{
	return (0);
}
