/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ultis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:14:36 by nprljic           #+#    #+#             */
/*   Updated: 2022/12/18 15:43:44 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	door_player_swap(char *c1, char *c2)
{
	char	temp;

	if (*c1 == 'D')
	{
		*c1 = 'E';
		*c2 = 'P';
	}
	else if (*c2 == 'E')
	{
		*c1 = '0';
		*c2 = 'D';
	}
	else
	{
		temp = *c1;
		*c1 = *c2;
		*c2 = temp;
	}
	return (0);
}

int	ft_swap(char *c1, char *c2, t_data *data)
{
	if (*c2 == 'C')
	{
		*c2 = 'P';
		if (*c1 == 'D')
			*c1 = 'E';
		else
			*c1 = '0';
		data->coins++;
		return (0);
	}
	if (data->coins == data->max_coin && *c2 == 'E')
	{
		ft_printf("!!SUCESS!!");
		data->sus = 1;
		return (1);
	}
	door_player_swap(c1, c2);
	return (0);
}

int	free2d(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (0);
}

void	destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->weed.img);
	mlx_destroy_image(data->mlx_ptr, data->wall.img);
	mlx_destroy_image(data->mlx_ptr, data->stay_right.img);
	mlx_destroy_image(data->mlx_ptr, data->stay_left.img);
	mlx_destroy_image(data->mlx_ptr, data->coin.img);
	mlx_destroy_image(data->mlx_ptr, data->door.img);
	mlx_destroy_image(data->mlx_ptr, data->stayondoor.img);
}

void	makeimages(t_data *data)
{
	data->weed.img = mlx_xpm_file_to_image(data->mlx_ptr, "art/weed32.xpm",
			&data->weed.width, &data->weed.height);
	data->wall.img = mlx_xpm_file_to_image(data->mlx_ptr, "art/wall32.xpm",
			&data->wall.width, &data->wall.height);
	data->stay_right.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"art/walk_right32.xpm", &data->stay_right.width,
			&data->stay_right.height);
	data->stay_left.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"art/walk_left32.xpm", &data->stay_left.width,
			&data->stay_left.height);
	data->coin.img = mlx_xpm_file_to_image(data->mlx_ptr, "art/coin32.xpm",
			&data->coin.width, &data->coin.height);
	data->door.img = mlx_xpm_file_to_image(data->mlx_ptr, "art/door32.xpm",
			&data->door.width, &data->door.height);
	data->stayondoor.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"art/stayondoor32.xpm", &data->stayondoor.width,
			&data->stayondoor.height);
}
