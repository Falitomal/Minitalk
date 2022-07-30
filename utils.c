/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:12:45 by jledesma          #+#    #+#             */
/*   Updated: 2022/07/30 19:18:57 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(1,*(s++), fd);
		}
	}
}

void	print_error(char *str)
{
	ft_putstr_fd(str, 1);
}

int	ft_atoi(const char *str)
{
	int 	i;
	int 	sign;
	int 	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		res *= 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
