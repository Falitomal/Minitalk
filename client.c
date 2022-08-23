/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:35:59 by jledesma          #+#    #+#             */
/*   Updated: 2022/08/16 18:10:35 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_bit(int pid, char *str, int len)
{
	int		i;
	int		pos;

	i = 0;
	while (i <= len)
	{
		pos = 0;
		while (pos < 7)
		{
			if ((str[i] >> pos) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			pos++;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid_server;
	char	*str;

	str = argv[2];
	if (argc != 3)
	{
		ft_printf(COLOR_RED "Wrong argument \n");
		return (0);
	}
	pid_server = ft_atoi(argv[1]);
	ft_printf(COLOR_RED "\nSendind msg with %d bytes \n", ft_strlen(str));
	ft_send_bit(pid_server, argv[2], ft_strlen(str));
	return (0);
}
