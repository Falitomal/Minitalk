/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::   */
/*   ft_printf_char.c                                  :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:55:09 by jledesma          #+#    #+#             */
/*   Updated: 2022/05/06 16:50:30 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** Funcion ft_print_char sirve para imprimir caracteres
*/
void	ft_printf_char(char c, int *i)
{
	write(1, &c, 1);
	*i += 1;
}
