/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:59:10 by nprljic           #+#    #+#             */
/*   Updated: 2022/12/18 14:21:51 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_side(t_data *data, int x, int y)
{
	if (data->look == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->stay_right.img, x, y);
	else if (data->look == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->stay_left.img, x, y);
}

void	exit_door(t_data *data, int x, int y, int z)
{
	if (data->matrix[z][data->i] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->door.img, x,
			y);
	else if (data->matrix[z][data->i] == 'D')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->stayondoor.img, x, y);
}

void	load_img(t_data *data, int x, int y, int z)
{
	char	*str;

	str = ft_itoa(data->move);
	if (data->matrix[z][data->i] == '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall.img, x,
			y);
		if (x == 0 && y == 0)
			mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0xFF00, str);
	}
	else if (data->matrix[z][data->i] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->weed.img, x,
			y);
	else if (data->matrix[z][data->i] == 'P')
		player_side(data, x, y);
	else if (data->matrix[z][data->i] == 'E' || data->matrix[z][data->i] == 'D')
		exit_door(data, x, y, z);
	else if (data->matrix[z][data->i] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->coin.img, x,
			y);
	x += 32;
	free(str);
}

int	render_switch(t_data *data, int y, int z)
{
	int	x;

	data->i = 0;
	x = 0;
	while (data->matrix[z][data->i])
	{
		load_img(data, x, y, z);
		x += 32;
		data->i++;
	}
	return (y);
}

int	render(t_data *data)
{
	int	y;
	int	z;

	y = 0;
	z = -1;
	if (data->win_ptr == NULL)
		return (1);
	while (data->matrix[++z])
	{
		render_switch(data, y, z);
		y += 32;
	}
	return (0);
}
