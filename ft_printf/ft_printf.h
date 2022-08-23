/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:18:45 by jledesma          #+#    #+#             */
/*   Updated: 2022/05/09 16:49:46 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_printf_char(char c, int *i);
void	ft_printf_int(int nb, int *i);
void	ft_printf_str(char *str, int *i);
void	ft_printf_hex(unsigned long long nb, int *i);
void	ft_printf_nb(unsigned int nb, int *i);
void	ft_printf_base(unsigned int n, char *base, int *i);

#endif