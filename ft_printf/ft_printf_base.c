/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:06:54 by jledesma          #+#    #+#             */
/*   Updated: 2022/05/16 13:25:15 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Funcion ft_check_base chequea que la base no tenga el mismo caracter dos veces
** y que no tenga simbolos + o -
*/

int	ft_check_base(char *base)
{
	int	no_error;
	int	count;
	int	count2;

	count = 0;
	no_error = 1;
	while (base[count] != '\0' && no_error)
	{
		count2 = count + 1;
		if (base[count] == '+' || base[count] == '-')
				no_error = 0;
		while (base[count2] != '\0' && no_error)
		{
			if (base[count] == base[count2])
				no_error = 0;
			count2++;
		}
		count++;
	}
	if (count < 2)
		no_error = 0;
	return (no_error);
}

/*
** Funcion ft_sizebase calcula el tamaño de la base 
*/
int	ft_sizebase(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

/*
** Funcion ft_print_n sirve para escribir los numeros de la base
*/

void	ft_print_n(unsigned int nbr, char *base, int num_base, int *i)
{
	char	res;

	if (nbr / num_base != 0)
		ft_print_n(nbr / num_base, base, num_base, i);
	res = base[nbr % num_base];
	ft_printf_char(res, i);
}

/*
** Funcion ft_print_base es la funcion que chequea la base y si es correcta
** Y luego mediante la funcion print_n imprime los numeros
*/
void	ft_printf_base(unsigned int n, char *base, int *i)
{
	int		no_error;
	int		num_base;

	no_error = ft_check_base(base);
	if (no_error)
	{
		num_base = ft_sizebase(base);
		ft_print_n(n, base, num_base, i);
	}
}
