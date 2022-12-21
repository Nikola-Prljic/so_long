/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:54:18 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/11 11:54:53 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_b;
	size_t	i_l;

	i_b = 0;
	if (big == 0 && len == 0)
		return (0);
	if (*little == '\0')
		return ((char *)(big));
	while (big[i_b])
	{
		i_l = 0;
		while (big[i_b + i_l] == little[i_l] && big[i_b + i_l] != '\0' && i_b
			+ i_l < len)
		{
			if (little[i_l + 1] == '\0')
				return ((char *)(&big[i_b]));
			i_l++;
		}
		i_b++;
	}
	return (0);
}

/*int main()
{
    char dest[] = "hello world junge!";
    char src[] = "w";
    printf("%s", ft_strnstr(dest, src, 6));
}*/