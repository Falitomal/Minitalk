/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:35:51 by jledesma          #+#    #+#             */
/*   Updated: 2022/09/09 12:27:53 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_bit_handler(int sig, siginfo_t *info, void *nothing)
{
	static unsigned char		c = 0;
	static int					pos = 7;
	static pid_t				pid_client = 0;

	(void)nothing;
	if (!pid_client)
		pid_client = info->si_pid;
	if (sig == SIGUSR2)
		c |= (1 << pos);
	pos--;
	if (pos < 0)
	{
		if (c == '\0')
		{
			kill(pid_client, SIGUSR1);
			pos = 7;
			pid_client = 0;
			write(1, "\n", 1);
			return ;
		}
		write(1, &c, 1);
		kill(pid_client, SIGUSR2);
		pos = 7;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	system("clear screen");
	sa.sa_sigaction = ft_bit_handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf(COLOR_GREEN "\nServer Active\nPID is: %d:\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
