/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:37:02 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/14 11:53:33 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include <string.h> */

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*s_char;
	size_t		i;

	s_char = s;
	i = 0;
	if (c == 0 && n == 0)
		return (0);
	while (i < n)
	{
		if (*s_char == (char)(c))
		{
			return ((void *)(s_char));
		}
		s_char++;
		i++;
	}
	return (0);
}
//if (c == '\0')
//	return ((void *)(&s_char[ft_strlen(s)]));
/* int	main(void)
{
	char s[] = {0, 2, 3, 4, 5};
	printf("%p\n", memchr(s, 0, 5));
	printf("%p", ft_memchr(s, 0, 5));
	//printf("%p\n", ft_memchr(s, 2 + 256, 3));
	//printf("%p\n", memchr(s, 258, 3));
	//printf("%d", (char)(258));
	
	//printf("%p", ft_memchr(s, 2, 3));
	//return (0);
	//char	*str;
	//int		size;

	//char	str[] = "hello world!";
	//str = "/|\x12\xff\x09\0\x42\042\0\42|\\";
	//size = 12;
	
	//printf("%s", (char *)ft_memchr(str, '\0', size));
} */
