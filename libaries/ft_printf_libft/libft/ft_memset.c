/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:01:52 by nprljic           #+#    #+#             */
/*   Updated: 2022/10/08 18:53:43 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include <stddef.h>
#include "libft.h"

void	*ft_memset(void *block, int c, size_t size)
{
	unsigned char	ic;
	unsigned char	*blocku;
	size_t			i;

	ic = c;
	blocku = block;
	i = 0;
	while (i < size)
	{
		blocku[i] = ic;
		i++;
	}
	return (block);
}

/*int main ()
{
  char str[] = "almost every programmer should know memset!";
  ft_memset (str,'-', 5);
  puts (str);
  
  return (0);
}*/
