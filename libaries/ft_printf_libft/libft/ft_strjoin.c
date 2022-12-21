/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:27:52 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/12 12:32:25 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include <unistd.h>
//#include "ft_strlen.c"
//#include "ft_strlcpy.c"
#include "libft.h"

static char	*ft_cpynonull(char *dest, char const *s1, int i)
{
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}

static char	*ft_cpynonull_s2(char *dest, char const *s2, size_t s2_len,
		size_t s1_len)
{
	size_t	i;

	i = 0;
	while (i < s2_len)
	{
		dest[s1_len] = s2[i];
		s1_len++;
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*dest;
	int		s1_len;
	size_t	s2_len;
	int		dest_len;

	if (!s1 || !s2)
		return (0);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest_len = s1_len + s2_len;
	dest = malloc(dest_len * sizeof(char) + 1);
	if (!dest)
		return (0);
	ft_cpynonull(dest, s1, i);
	ft_cpynonull_s2(dest, s2, s2_len, s1_len);
	dest[dest_len] = '\0';
	return (dest);
}
/* int main()
{
    char *s1 = "my favorite animal is";
    char *s2 = " ";
    char *s3 = "the nyancat";
    char *res = ft_strjoin(ft_strjoin(s1, s2), s3);

    printf("%s", res);
} */