/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:00:04 by jledesma          #+#    #+#             */
/*   Updated: 2022/05/15 15:56:36 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Funcion ft_print_char sirve para imprimir numero enteros 
*/

void	ft_printf_int(int nb, int *i)
{
	long long	nbr;

	nbr = (long long) nb;
	if (nbr < 0)
	{
		ft_printf_char('-', i);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_printf_int(nbr / 10, i);
		nbr %= 10;
	}
	ft_printf_char(nbr + '0', i);
}
