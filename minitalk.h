/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:57:21 by jledesma          #+#    #+#             */
/*   Updated: 2022/07/30 19:28:11 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define COLOR_GREEN = "\033[0;32m"
# define COLOR_RED = "\033[0;31m"
# define COLOR_BLUE = "\033[0;34m"
# define COLOR_END = "\033[0m"

# include "signal.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "./ft_printf/ft_printf.h"

# define DELAY 300

void	print_error(char *str);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
#endif