/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:46:11 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/10 18:17:54 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include "ft_isascii.c"
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*s1 || *s2) && i < n)
	{
		if (*s1 != *s2)
		{
			if (ft_isascii(*s1) == 1 && ft_isascii(*s2) == 1)
				return (*s1 - *s2);
			return ((*s1 - *s2) * -1);
		}
		s1++;
		s2++;
		i++;
	}
	return (0);
}
/* int	main(void)
{
	char *s1 = "\x12\xff\x65\x12\xbd\xde\xad";
	char *s2 = "\x12\x02";
	size_t size = 6;
	printf("%d", ft_strncmp(s1, s2, size));
} */