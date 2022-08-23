/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:35:51 by jledesma          #+#    #+#             */
/*   Updated: 2022/08/16 18:07:04 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_bit_handler(int sig)
{
	static char		c = 0;
	static int		pos = 0;
	int				bit;

	if (sig == SIGUSR1)
		bit = 0;
	else if (sig == SIGUSR2)
		bit = 1;
	else
		exit(EXIT_FAILURE);
	c += bit << pos++;
	if (pos == 7)
	{
		ft_printf(COLOR_GREEN "%c", c);
		if (!c)
			ft_printf("\n");
		pos = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = ft_bit_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	ft_printf(COLOR_GREEN "\nServer Active\nPID is: %d:\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
