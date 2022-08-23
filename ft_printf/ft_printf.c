/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:01:54 by jledesma          #+#    #+#             */
/*   Updated: 2022/05/15 16:38:43 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Funcion ft_print_all sirve para saber el tipo de argumento que imprimir
*/

void	ft_print_all(const char *str, int *i, va_list args, int x)
{
	if (str[x + 1] == '%')
		ft_printf_char('%', i);
	else if (str[x + 1] == 'c')
		ft_printf_char(va_arg(args, int), i);
	else if (str[x + 1] == 's')
		ft_printf_str(va_arg(args, char *), i);
	else if (str[x + 1] == 'p')
	{
		ft_printf_str("0x", i);
		ft_printf_hex(va_arg(args, unsigned long long), i);
	}
	else if (str[x + 1] == 'd')
		ft_printf_int(va_arg(args, int), i);
	else if (str[x + 1] == 'i')
		ft_printf_int(va_arg(args, int), i);
	else if (str[x + 1] == 'u')
		ft_printf_nb(va_arg(args, unsigned int), i);
	else if (str[x + 1] == 'x')
		ft_printf_base(va_arg(args, unsigned int), "0123456789abcdef", i);
	else if (str[x + 1] == 'X')
		ft_printf_base(va_arg(args, unsigned int), "0123456789ABCDEF", i);
}

/*
** Funcion ft_print_tf es la principal que recorre el string para imprimir
** usa la funcion print_all para gestionar los tipos de argumentos 
** guardando la posicion y si no imprime el caracter
*/

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	j = 0;
	i = 0;
	va_start(args, str);
	while (str[j])
	{
		if (str[j] == '%')
		{
			ft_print_all(str, &i, args, j);
			j++;
		}
		else
			ft_printf_char(str[j], &i);
		j++;
	}
	va_end(args);
	return (i);
}
