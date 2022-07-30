/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:53:23 by jledesma          #+#    #+#             */
/*   Updated: 2022/07/30 19:45:00 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

typedef struct msg_t
{
	char	letter;
	size_t	i;
}			t_msg;

void	handler(int bit)
{
	size_t	i;
	t_msg	msg;

	i = 0;
	msg.letter += ((bit & i) << msg.i);
	msg.i++;
	if (msg.i == 7)
	{
		ft_printf("%c", msg.letter);
		if (!msg.letter)
			ft_printf("\n");
		msg.i = 0;
		msg.letter = 0;
	}
}

int	main(int argc, char **argv)
{
	printf("Welcome to UNIX signals, AKA `Minitalk`");
	printf("This server PID ---> [%d] <---", getpid());
	while (1)
	{
		signal(SIGUSR2, handler);
		signal(SIGUSR1, handler);
	}
	return (0);
}
