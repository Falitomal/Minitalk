/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:57:21 by jledesma          #+#    #+#             */
/*   Updated: 2022/08/16 16:56:51 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define COLOR_GREEN  "\033[0;32m"
# define COLOR_RED  "\033[0;31m"
# define COLOR_BLUE  "\033[0;34m"
# define COLOR_END  "\033[0m"
# include "stdlib.h"
# include <unistd.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

void	confirm(int signal);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nbr);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
#endif