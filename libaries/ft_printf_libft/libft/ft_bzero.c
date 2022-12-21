/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:53:26 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/08 18:54:47 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ctype.h>
//#include <stdio.h>
//#include <strings.h>
//#include <stddef.h>
#include "libft.h"

void	ft_bzero(void *block, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = block;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}
/*int main()
{
    char str[] = "";

    bzero(str, 3);
    puts(str);
}*/