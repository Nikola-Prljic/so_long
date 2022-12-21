/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:54:58 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/10 11:32:48 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_memcpy.c"
#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	char	*dst;

	temp = (char *)src;
	dst = (char *)dest;
	if (temp < dst)
	{
		while (n--)
			dst[n] = temp[n];
	}
	else
		ft_memcpy(dest, temp, n);
	return (dest);
}
/*
int	main(void)
{
	//int size = 2147483647;
	int size = 128 * 1024 * 1024;
	char *dst = (char *)malloc(sizeof(char) * size);
	char *src = (char *)malloc(sizeof(char) * size);
	//char dest[] = " ";
	//char src[] = "123";

	ft_memmove(dst , src, size);
	puts(dst);
}
*/