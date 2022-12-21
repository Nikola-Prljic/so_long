/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:36:17 by nprljic           #+#    #+#             */
/*   Updated: 2022/11/03 14:13:08 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t num, char x)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16, x);
		ft_put_ptr(num % 16, x);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else if (x == 'x')
			ft_putchar_fd((num - 10 + 'a'), 1);
		else
			ft_putchar_fd((num - 10 + 'A'), 1);
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (len += write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	ft_put_ptr(ptr, 'x');
	len += ft_ptr_len(ptr);
	return (len);
}

int	ft_printhex(unsigned int num, const char x)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	ft_put_ptr(num, x);
	len += ft_ptr_len(num);
	return (len);
}
/* int	main(void)
{
	//int i = 10;
	//ft_printf("you = %c\n%c %c%c %c %s", '0', 'I', 'a', 'm', 'a', "nyancat!");
	printf("\nlen = %i\n", ft_putptr(0));
	//printf("\nlen ori = %i\n", printf(" %p ", &i));

	//ft_printf(" %c %c %c ", '0' + 256, '1');
	//printf("\n %c %c %c ", '0'+ 258, '1');
	//printf("%d %i", 11, 11);
	//printf("1312");
} */