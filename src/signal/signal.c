/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:06:12 by ahekinci          #+#    #+#             */
/*   Updated: 2025/05/27 19:315 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "minishell.h"
#include "command.h"
#include <readline/readline.h>

int	g_signal = 0;

void	set_signal_handler(t_signal s_type)
{
	g_signal = 0;
	if (s_type == HERE_SIG)
	{
		rl_event_hook = do_noop;
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handle_sigint_here);
	}
	else if (s_type == EXEC_SIG)
	{
		rl_event_hook = NULL;
		signal(SIGQUIT, handle_sigquit);
		signal(SIGINT, handle_sigint_exec);
	}
	else if (s_type == PROMT_SIG)
	{
		rl_event_hook = NULL;
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handle_sigint_prompt);
	}
}
