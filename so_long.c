/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:38:53 by nprljic           #+#    #+#             */
/*   Updated: 2022/12/15 16:55:46 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sucess_screen(t_data *data)
{
	char	*move;

	if (data->win_ptr == NULL)
		return (1);
	move = ft_itoa(data->move);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->win.img, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 250, 450, 0xFF00,
		"Your move count:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 350, 450, 0xFF00, move);
	free(move);
	return (0);
}

int	make_window(t_data *data, int heigt, int with)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, with, heigt, "SO LONG");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	return (0);
}

int	game_window(t_data *data)
{
	data->sus = 0;
	data->move = 0;
	if (make_window(data, data->max_y * 32, data->max_x * 32) != 0)
		return (MLX_ERROR);
	makeimages(data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &keypress_move, data);
	mlx_hook(data->win_ptr, 17, 0, &x_close, data);
	mlx_loop(data->mlx_ptr);
	destroy(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (0);
}

int	open_window(t_data data)
{
	game_window(&data);
	if (data.sus == 1)
	{
		if (make_window(&data, 600, 600) != 0)
			return (MLX_ERROR);
		data.win.path = "art/win32.xpm";
		data.win.img = mlx_xpm_file_to_image(data.mlx_ptr, data.win.path,
				&data.win.width, &data.win.height);
		mlx_loop_hook(data.mlx_ptr, &sucess_screen, &data);
		mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &esc_exit, &data);
		mlx_hook(data.win_ptr, 17, 0, &x_close, &data);
		mlx_loop(data.mlx_ptr);
		mlx_destroy_image(data.mlx_ptr, data.win.img);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (argv[1][0] < '1' || argv[1][0] > '5' || ft_strlen(argv[1]) != 5)
		{
			if (ft_scmp(".ber", argv[1]) == 1)
				return (ft_printf("ERROR\nChoose from map 1 - 5.ber"));
		}
		data.coins = 0;
		data.look = 0;
		data.matrix = ft_matrix(argv[1]);
		if (check_map(&data) != 0 || pathcheck(&data) != 0)
			free2d(data.matrix);
		else
		{
			free2d(data.matrix);
			data.matrix = ft_matrix(argv[1]);
			open_window(data);
			free2d(data.matrix);
		}
	}
	else
		ft_printf("ERROR\nJust 1 args with 1.ber - 5.ber!");
	return (0);
}
