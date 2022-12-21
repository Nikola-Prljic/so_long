/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:00:58 by nprljic           #+#    #+#             */
/*   Updated: 2022/12/09 11:50:16 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #1 creates a new malloc string just for the first time
char	*ft_new_str(int fd, char *remain)
{
	int		ret;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ret = 1;
	while (!ft_getchr(remain, '\n') && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(remain);
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		remain = ft_linejoin(remain, buf);
	}
	free(buf);
	return (remain);
}

// #2 prints the line
char	*ft_putline(char *remain)
{
	char	*line;
	int		i;

	if (!*remain)
		return (NULL);
	i = 0;
	while (remain[i] && remain[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (remain[i] && remain[i] != '\n')
	{
		line[i] = remain[i];
		i++;
	}
	if (remain[i] == '\n')
	{
		line[i] = remain[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// #3 malloc a new without the printed string. frees the old one.
char	*ft_next_str(char *remain)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	while (remain[i] && remain[i] != '\n')
		i++;
	if (!remain[i])
	{
		free(remain);
		return (NULL);
	}
	str = (char *)malloc((int_strlen(remain) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	x = 0;
	while (remain[i])
		str[x++] = remain[i++];
	str[x] = '\0';
	free(remain);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remain = ft_new_str(fd, remain);
	if (!remain)
		return (NULL);
	line = ft_putline(remain);
	remain = ft_next_str(remain);
	return (line);
}

/* int main()
{
    int fd;
    int x = 0;
    char *str;

    fd = open("test.txt", O_RDONLY);
    while(x++ < 10)
        printf("line %i = %s", x, str = get_next_line(fd));
    //printf("%s", get_next_line(fd));
    close(fd);
    return(0);
} */