/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:06:12 by ahekinci          #+#    #+#             */
/*   Updated: 2025/05/22 08:20:55 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

void	handle_signal(int sig, siginfo_t *info, void *context) // check
{
	if (sig == SIGINT)
	{ // crtl + c
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{ // crtl + slash
		rl_on_new_line();
		rl_redisplay();
	}

}

void	setup_signal(struct sigaction *sa)
{
	sa->sa_sigaction = handle_signal;
	sa->sa_flags = SA_SIGINFO;
	sigemptyset(&sa->sa_mask);

	if (sigaction(SIGINT, sa, NULL) == -1)
		return ;
	if (sigaction(SIGQUIT, sa, NULL) == -1)
		return ;
}
