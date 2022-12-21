/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:18:17 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/14 12:10:53 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
	{
		return ((char *)(&s[ft_strlen(s)]));
	}
	while (*s)
	{
		if (*s == (char)(c))
		{
			return ((char *)(s));
		}
		s++;
	}
	return (0);
}
/* int main()
{
    char s[] = "tripouille";
    printf("%s", ft_strchr(s, 't' + 256));
} */