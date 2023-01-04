/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:22:09 by nprljic           #+#    #+#             */
/*   Updated: 2022/12/18 15:42:08 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libaries/libft.h"
# include "libaries/ft_printf.h"
# include "libaries/get_next_line.h"
# include "mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define MLX_ERROR 1

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
	char	*path;
}			t_img;

typedef struct s_data
{
	int		i;
	int		move;
	int		x;
	int		y;
	int		max_y;
	int		max_x;
	int		start;
	int		end;
	int		coins;
	int		path_coins;
	int		max_coin;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	win;
	t_img	weed;
	t_img	wall;
	t_img	stay_left;
	t_img	stay_right;
	t_img	coin;
	t_img	door;
	t_img	stayondoor;
	int		cur_img;
	char	**matrix;
	int		sus;
	int		look;
}			t_data;

typedef struct s_path
{
	int		x;
	int		y;
}			t_path;

char		**ft_matrix(char *str);
int			free2d(char **matrix);
int			ft_swap(char *c1, char *c2, t_data *data);
int			check_map(t_data *data);
int			pathcheck(t_data *data);
int			map_test(t_data *data, t_path *test);
int			ft_scmp(char *s1, char *s2);
int			render(t_data *data);
int			x_close(t_data *data);
int			esc_exit(int keysym, t_data *data);
int			ft_move(int keysym, t_data *data);
int			keypress_move(int keysym, t_data *data);
void		makeimages(t_data *data);
void		destroy(t_data *data);

#endif
