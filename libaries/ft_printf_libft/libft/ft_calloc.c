/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:27:18 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/19 14:10:24 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdint.h>
//#include <stdio.h>
//#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (count == 0xffffffffffffffff || size == 0xffffffffffffffff)
	{
		return (0);
	}
	ret = (void *)malloc(size * count);
	if (!ret)
		return (0);
	ft_bzero(ret, size * count);
	return (ret);
}
/* int main()
{
    size_t size = SIZE_MAX;

    //void * d1 = ft_calloc(size, sizeof(int));
	//void * d2 = calloc(size, sizeof(int));

    //printf("%p\n", ft_calloc(1, 1));
    //printf("%p\n", calloc(1, SIZE_MAX));
    //printf("%ld", size * size);
    //printf("%p", ft_calloc(INT_MAX, INT_MAX));
    //printf("%p \n", ft_calloc(size, sizeof(int)));
    //printf("%p", calloc(size, sizeof(int)));
} */