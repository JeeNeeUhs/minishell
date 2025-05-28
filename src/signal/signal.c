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

int  g_signal = 0;

/*During an execve(2), the dispositions of handled signals are reset to the default; the dispositions of ignored signals are left unchanged
	in PROMT_SIG :
		-> SIGINT : Print new prompt, and ignore the current line
		-> SIGQUIT : Igrore,
	int EXEC_SIG :
		-> SIGINT : just print new_line after newline main process will turn into main while loop
		-> SIGQUIT : Print "Quit (core dumped)\n" and ignore the current line
	in HERE_SIG :
		-> SIGINT : cancel everything and turn into main while loop,
		-> SIGQUIT : Ignore
*/
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
