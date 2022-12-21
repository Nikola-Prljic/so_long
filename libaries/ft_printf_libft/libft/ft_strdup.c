/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:36:02 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/12 13:39:18 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include "ft_strlen.c" */
#include "libft.h"
//#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!tmp)
		return (0);
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

/* int main()
{
    char *str;

    str = "under your bead is a nyancat!";

    printf("%s", ft_strdup(str));
} */