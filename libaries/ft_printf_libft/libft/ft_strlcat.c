/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:53:46 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/17 15:39:22 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_strlen.c"
#include "libft.h"
/* #include <stddef.h>
#include <stdio.h> */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;
	size_t	y;

	src_size = ft_strlen(src);
	if (dst == 0 && size == 0)
		return (0);
	dst_size = ft_strlen(dst);
	y = dst_size;
	i = 0;
	if (size == 0 || size <= dst_size)
		return (src_size + size);
	while (src[i] && i < size - dst_size - 1)
	{
		dst[y] = src[i];
		y++;
		i++;
	}
	dst[y] = '\0';
	return (dst_size + src_size);
}
/* int main()
{
    char *src = "the cake is a lie !\0I'm hidden lol\r\n";
    char buff2[4] = "";
    
    printf("%ld\n", ft_strlcat(buff2, src, 4));
} */