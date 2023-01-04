/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:14:24 by nprljic           #+#    #+#             */
/*   Updated: 2022/12/14 12:04:40 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mapsize(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->matrix[y] != NULL)
	{
		while (data->matrix[y][x])
			x++;
		y++;
	}
	data->max_y = y;
	data->max_x = x;
	return (0);
}

void	replace(t_data *data, t_path pos, char zero)
{
	if (data->matrix[pos.y][pos.x] == 'P')
		data->matrix[pos.y][pos.x] = '0';
	if (data->matrix[pos.y][pos.x] == 'E')
	{
		data->matrix[pos.y][pos.x] = '0';
		data->end = 1;
	}
	if (data->matrix[pos.y][pos.x] == 'C')
	{
		data->matrix[pos.y][pos.x] = '0';
		data->path_coins++;
	}
	if (pos.y < 0 || pos.y >= data->max_y || pos.x < 0 || pos.x >= data->max_x
		|| data->matrix[pos.y][pos.x] != zero)
		return ;
	data->matrix[pos.y][pos.x] = 'F';
	replace(data, (t_path){pos.x + 1, pos.y}, zero);
	replace(data, (t_path){pos.x - 1, pos.y}, zero);
	replace(data, (t_path){pos.x, pos.y + 1}, zero);
	replace(data, (t_path){pos.x, pos.y - 1}, zero);
}

int	pathcheck(t_data *data)
{
	t_path	pos;

	data->end = 0;
	data->path_coins = 0;
	pos.y = data->x;
	pos.x = data->x;
	replace(data, pos, '0');
	if (data->end != 1)
	{
		ft_printf("ERROR\n!!! NOWAY FROM START TO EXIT !!!\n");
		return (1);
	}
	if (data->path_coins != data->max_coin)
	{
		ft_printf("ERROR\n!!! NOWAY TO ALL COINS !!!\n");
		return (2);
	}
	return (0);
}

int	check_map(t_data *data)
{
	int		i;
	t_path	test;

	i = 0;
	data->max_coin = 0;
	mapsize(data);
	i = map_test(data, &test);
	if ((test.x != 1 || test.y != 1) && i == 0)
		i = 3;
	if (i == 1)
	{
		ft_printf("!!! ERROR  !!!\n");
		ft_printf("Map has other characters than 0, 1, C, P or E !!");
	}
	else if (i == 2)
		ft_printf("!!! ERROR  !!!\n!! Map has no wall around it aka 1 !!");
	else if (i == 3)
		ft_printf("!!! ERROR  !!!\n!! Map has no start or end !!");
	else if (data->max_coin == 0)
	{
		i = 4;
		ft_printf("\n!!! ERROR  !!!\n!! NEED AT LEAST ONE COIN !!");
	}
	return (i);
}

int	ft_scmp(char *s1, char *s2)
{
	int	i;

	i = 1;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
