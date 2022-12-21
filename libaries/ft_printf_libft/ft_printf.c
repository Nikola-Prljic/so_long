/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:14:39 by nprljic           #+#    #+#             */
/*   Updated: 2022/11/03 16:45:07 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
//#include <stdio.h>
//#include <stdio.h>
//#include <string.h>
//#include <unistd.h>

int	ft_putchar(char c)
{
	int	len;

	len = 0;
	len += write(1, &c, 1);
	return (len);
}

int	ft_switch(va_list args, const char chr)
{
	int	len;

	len = 0;
	if (chr == '%')
		len += write(1, "%", 1);
	else if (chr == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (chr == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (chr == 'x' || chr == 'X')
		len += ft_printhex(va_arg(args, unsigned int), chr);
	else if (chr == 'i' || chr == 'd')
		len += ft_print_int(va_arg(args, int));
	else if (chr == 'u')
		len += ft_print_int_un(va_arg(args, unsigned int));
	else if (chr == 'p')
		len += ft_putptr((unsigned long)va_arg(args, void *));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && !(str[i + 1] == '\0'))
			len += ft_switch(args, str[++i]);
		else
		{
			if (str[i] == '%')
				break ;
			len += write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (len);
}
