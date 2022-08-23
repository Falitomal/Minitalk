/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:53:14 by jledesma          #+#    #+#             */
/*   Updated: 2022/05/15 15:55:48 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** Funcion ft_print_hex sirve para imprimir en base hexadecimal caracteres
*/
void	ft_printf_hex(unsigned long long nb, int *i)
{
	if (nb >= 16)
		ft_printf_hex(nb / 16, i);
	ft_printf_char("0123456789abcdef"[nb % 16], i);
}
