/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:59:23 by jledesma          #+#    #+#             */
/*   Updated: 2022/05/15 16:00:41 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Funcion ft_print_str para imprimir una cadena de caracteres(strings)
*/

void	ft_printf_str(char *str, int *i)
{
	int	x;

	if (!str)
	{
		ft_printf_str("(null)", i);
		return ;
	}
	x = 0;
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
	*i += x;
}
