/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmatrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:15:10 by nprljic           #+#    #+#             */
/*   Updated: 2023/04/18 17:38:08 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

char	*ft_mapstr(int fd)
{
	int		ret;
	char	*buf;
	char	*remain;

	remain = NULL;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		remain = ft_linejoin(remain, buf);
	}
	free(buf);
	return (remain);
}

char	**ft_matrix(char *map)
{
	int		fd;
	char	*str;
	char	*path;
	char	**matrix;

	path = ft_strjoin("maps/map", map);
	fd = open(path, O_RDONLY);
	free(path);
	str = ft_mapstr(fd);
	close(fd);
	matrix = ft_split(str, '\n');
	free(str);
	return (matrix);
}
