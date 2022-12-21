/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:56:50 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/11 16:20:18 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"
//#include "ft_isascii.c"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s1_chr;
	const char	*s2_chr;

	s1_chr = s1;
	s2_chr = s2;
	while (0 < n)
	{
		if (*s1_chr != *s2_chr)
		{
			if (ft_isascii(*s1_chr) == 1 && ft_isascii(*s2_chr) == 1)
				return (*s1_chr - *s2_chr);
			return ((*s1_chr - *s2_chr) * -1);
		}
		s1_chr++;
		s2_chr++;
		n--;
	}
	return (0);
}
/*int	main(void)
{
	char	*s1;
	char	*s2;
	size_t	size;

	s1 = "\xff\0\0\xaa\0\xde\xffMACOSX\xff";
	s2 = "a";
	
	size = 8;
	
	printf("%d", memcmp(s1, s2, size));
}*/