/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptest_ultis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:32:10 by nprljic           #+#    #+#             */
/*   Updated: 2022/12/15 15:45:39 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_sec01(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C')
		return (0);
	return (1);
}

int	map_test_expendet(t_data *data, int y, int x, t_path *test)
{
	if (is_sec01(data->matrix[y][x]) == 1)
		return (1);
	if (data->matrix[0][x] != '1' || data->matrix[y][0] != '1'
		|| data->matrix[data->max_y - 1][x] != '1'
		|| data->matrix[y][data->max_x - 1] != '1')
		return (2);
	if (data->matrix[y][x] == 'P')
	{
		data->y = y;
		data->x = x;
		test->x++;
	}
	if (data->matrix[y][x] == 'E')
		test->y++;
	return (0);
}

int	map_test(t_data *data, t_path *test)
{
	int		x;
	int		y;
	int		error;

	y = 0;
	error = 0;
	test->x = 0;
	test->y = 0;
	while (data->matrix[y] != NULL)
	{
		x = 0;
		while (data->matrix[y][x])
		{
			error = map_test_expendet(data, y, x, test);
			if (error > 0)
				return (error);
			if (data->matrix[y][x] == 'C')
				data->max_coin++;
			x++;
		}
		y++;
	}
	return (error);
}
