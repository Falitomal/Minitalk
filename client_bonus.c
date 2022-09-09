/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:35:59 by jledesma          #+#    #+#             */
/*   Updated: 2022/09/09 12:33:42 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_send_bit(int pid, unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		if (bit == '1')
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(350);
	}
}

void	sign_recived(int signal)
{
	static int	signr = 0;

	if (signal == SIGUSR2)
		signr++;
	else
	{
		ft_printf(COLOR_BLUE "\n %d bytes recibed \n", signr);
		exit(0);
	}
}

int	ft_atoi(const char *c)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (c[i] != '\0')
	{
		result *= 10;
		result += c[i] - 48;
		i++;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int			i;
	char		*str;
	int			pid_server;

	i = 0;
	str = argv[2];
	if (argc != 3)
	{
		ft_printf(COLOR_RED "Wrong argument \n");
		return (1);
	}
	signal(SIGUSR1, sign_recived);
	signal(SIGUSR2, sign_recived);
	while (i <= ft_strlen(str))
	{
		pid_server = ft_atoi(argv[1]);
		ft_send_bit(pid_server, str[i]);
		i++;
	}
	while (1)
		pause();
	return (0);
}
