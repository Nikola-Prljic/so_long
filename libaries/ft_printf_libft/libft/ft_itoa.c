/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:33:10 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/16 17:29:47 by nprljic          ###   ########.fr       */
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

static char	*numtostr(long nb, char *str)
{
	int	i;

	i = size_num(nb);
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
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;

	nb = n;
	str = (char *)malloc((size_num(nb) + 1) * sizeof(char));
	if (!str)
		return (0);
	if (nb == 0 || nb == -0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = numtostr(nb, str);
	return (str);
}
/* int	main(void)
{
	//int i = 333;
	printf("%s\n", ft_itoa(4000));
	//printf("%d", 2147483647);
	//printf("%s", to_string(INT_MAX));
	//sprintf()
} */