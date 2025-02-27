/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:06:12 by ahekinci          #+#    #+#             */
/*   Updated: 2025/02/27 12:18:30 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
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
