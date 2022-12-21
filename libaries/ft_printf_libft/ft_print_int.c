/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:58:28 by nprljic           #+#    #+#             */
/*   Updated: 2022/11/03 16:43:32 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fd_size_nbr(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_make_int(int num)
{
	if (num == -2147483648)
	{
		ft_putchar_lol('-');
		ft_putchar_lol('2');
		ft_make_int(147483648);
	}
	else if (num < 0)
	{
		ft_putchar_lol('-');
		ft_make_int(-num);
	}
	else if (num > 9)
	{
		ft_make_int(num / 10);
		ft_make_int(num % 10);
	}
	else
	{
		ft_putchar_lol(num + '0');
	}
}

int	ft_print_int(int num)
{
	ft_make_int(num);
	return (fd_size_nbr(num));
}

void	ft_putnbr_u(unsigned long nb)
{
	if (nb > 9)
	{
		ft_putnbr_u(nb / 10);
		ft_putnbr_u(nb % 10);
	}
	else
	{
		ft_putchar_lol(nb + '0');
	}
}

int	ft_print_int_un(unsigned long num)
{
	ft_putnbr_u(num);
	return (fd_size_nbr(num));
}
