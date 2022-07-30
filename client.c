/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:53:14 by jledesma          #+#    #+#             */
/*   Updated: 2022/07/30 19:25:18 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	send_bit(int pid, char *str, size_t len)
{
	size_t	i;
	int		pos;

	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		pos = 0;
		while (pos < 8)
		{
			if ((str[i] >> pos) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			pos++;
			usleep(DELAY);
		}
	}
}

int	main(int argc, char **argv)
{
	int pid;
	char *str;
	int len;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		len = ft_strlen(str);
		send_bit(pid, str, len);
	}
	else
	{
		print_error("Fatal error : argument invalid");
	}
	return (0);
}
