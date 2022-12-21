/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:17:59 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/17 11:33:48 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <limits.h>
//#include <stdio.h>
//#include <string.h>

static int	size_num(long n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		return (i = 1);
	}
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	put0_min(long nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else
	{
		ft_putchar_fd('0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	nb;
	char	str[10];

	nb = n;
	i = size_num(nb);
	if (nb == 0 || nb == -0 || nb == -2147483648)
	{
		put0_min(nb, fd);
		return ;
	}
	str[i--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	write(fd, str, ft_strlen(str));
}

/* int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
} */