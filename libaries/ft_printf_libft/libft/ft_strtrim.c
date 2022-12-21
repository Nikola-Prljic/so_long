/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:49:17 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/13 12:50:24 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h>
#include "ft_substr.c" */

static int	starting(char const *s1, char const *set)
{
	int	a;
	int	i;
	int	start;

	a = 1;
	i = 0;
	start = 0;
	while (a != 0)
	{
		a = 0;
		while (set[i])
		{
			while (s1[start] == set[i])
			{
				start++;
				a++;
			}
			i++;
		}
		i = 0;
	}
	return (start);
}

static int	ending(char const *s1, char const *set)
{
	int	a;
	int	i;
	int	len;

	a = 1;
	i = 0;
	len = ft_strlen(s1) - 1;
	while (a != 0)
	{
		a = 0;
		while (set[i])
		{
			while (s1[len] == set[i])
			{
				len--;
				a++;
			}
			i++;
		}
		i = 0;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	len;

	if (!s1)
	{
		return (0);
	}
	len = (int)ft_strlen(s1);
	start = starting(s1, set);
	if (start >= len)
		return (ft_substr(s1, start, len));
	else
		len = ending(s1, set);
	return (ft_substr(s1, start, (len - start + 1)));
}
/*  int	main(void)
{
	char *s1 = "  \t \t \n   \n\n\n\t";
	char *s2 = "";
	printf("%s", ft_strtrim(s1, s2));
} */