/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:14:55 by nprljic           #+#    #+#             */
/*   Updated: 2022/12/18 15:41:56 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_d(int keysym, t_data *data, int i)
{
	if ((keysym == XK_d || keysym == XK_Right) && data->matrix[data->y][data->x
		+ 1] != '1')
	{
		i = ft_swap(&data->matrix[data->y][data->x],
				&data->matrix[data->y][data->x + 1],
				data);
		data->x++;
		data->look = 0;
		data->move++;
	}
	return (i);
}

int	move_a(int keysym, t_data *data, int i)
{
	if ((keysym == XK_a || keysym == XK_Left) && data->matrix[data->y][data->x
		- 1] != '1')
	{
		i = ft_swap(&data->matrix[data->y][data->x],
				&data->matrix[data->y][data->x - 1],
				data);
		data->x--;
		data->look = 1;
		data->move++;
	}
	return (i);
}

int	move_ws(int keysym, t_data *data, int i)
{
	if ((keysym == XK_s || keysym == XK_Down) && data->matrix[data->y
			+ 1][data->x] != '1')
	{
		i = ft_swap(&data->matrix[data->y][data->x], &data->matrix[data->y
				+ 1][data->x], data);
		data->y++;
		data->move++;
	}
	if ((keysym == XK_w || keysym == XK_Up) && data->matrix[data->y
			- 1][data->x] != '1')
	{
		i = ft_swap(&data->matrix[data->y][data->x], &data->matrix[data->y
				- 1][data->x], data);
		data->y--;
		data->move++;
	}
	return (i);
}

int	ft_move(int keysym, t_data *data)
{
	int	i;

	i = 0;
	i = move_ws(keysym, data, i);
	i = move_d(keysym, data, i);
	i = move_a(keysym, data, i);
	if (i == 1)
		x_close(data);
	return (0);
}

int	esc_exit(int keysym, t_data *data)
{
	int	i;

	i = 0;
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		return (1);
	}
	return (0);
}
