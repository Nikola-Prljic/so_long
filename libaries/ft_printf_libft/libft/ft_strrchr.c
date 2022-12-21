/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:53:11 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/15 11:50:42 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <unistd.h>
//#include <string.h>
//#include "ft_strlen.c"
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	str_len;

	str_len = ft_strlen(s);
	while (str_len >= 0)
	{
		if (s[str_len] == (char)(c))
			return ((char *)(&s[str_len]));
		str_len--;
	}
	return (0);
}
/*int main()
{
    char str[] = "hello 123 144";
    printf("%s", ft_strrchr(str , 'h'));
}*/