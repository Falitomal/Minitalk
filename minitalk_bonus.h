/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:57:21 by jledesma          #+#    #+#             */
/*   Updated: 2022/09/07 12:27:35 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# define COLOR_GREEN  "\033[0;32m"
# define COLOR_RED  "\033[0;31m"
# define COLOR_BLUE  "\033[0;34m"
# define COLOR_END  "\033[0m"
# include "stdlib.h"
# include <unistd.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

/* Client */
void		sign_resolved(int signal);
static void	ft_send_bit(int pid, unsigned char octet);

/* Server */
void		exit_sig(int signal);
static void	ft_bit_handler(int sig, siginfo_t *info, void *nothing);

/* Utils */
int			ft_strlen(char *str);
int			ft_atoi(const char *str);
#endif