/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:38:58 by nprljic           #+#    #+#             */
/*   Updated: 2022/12/07 11:54:20 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_printhex(unsigned int num, const char x);
int		ft_print_int(int num);
int		ft_print_int_un(unsigned long num);
int		ft_putptr(unsigned long long ptr);
void	ft_putchar_lol(char c);

#endif