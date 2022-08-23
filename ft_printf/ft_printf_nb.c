/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:09:02 by jledesma          #+#    #+#             */
/*   Updated: 2022/05/15 15:58:48 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** Funcion ft_print_nb para imprimir un numero decimal en base 10
*/
void	ft_printf_nb(unsigned int nb, int *i)
{
	if (nb >= 10)
	{
		ft_printf_nb(nb / 10, i);
		nb %= 10;
	}
	ft_printf_char(nb + '0', i);
}
