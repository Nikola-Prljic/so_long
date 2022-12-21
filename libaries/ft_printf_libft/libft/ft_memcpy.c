/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:29:07 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/11 17:43:31 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include <stddef.h>
//#include <unistd.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_char;
	const char	*src_char;
	size_t		i;

	if (dest == 0 && src == 0)
		return (dest);
	i = 0;
	dest_char = dest;
	src_char = src;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}
/*int    main()
{
    char    src[] = "Willkommen";
    char    dest[100];

    char    *destptr = ft_memcpy(dest, src, strlen(src) + 1);
    //char    *destptr = memcpy(dest, src, strlen(src) + 1);

    printf("src: %s\n", src);
    printf("dest: %s\n", dest);

    printf("destptr: %p\n", destptr);
    printf("       : %p\n", dest);
}*/