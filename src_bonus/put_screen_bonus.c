/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_screen_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:34:47 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/18 15:34:27 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_square(t_win *win, int x, int y, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			my_pixel_put(win, x + j, y + i, 0x6f00ff);
			j += 1;
		}
		i += 1;
	}
}

static void	put_point(t_win *win, t_plr *plr_data, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < plr_data->x_win * SCALE_MAP)
	{
		j = 0;
		while (j < plr_data->y_win * SCALE_MAP)
		{
			my_pixel_put(win, i, j, 0x00aaff);
			++j;
		}
		i++;
	}
	i = -SIZE_POINT / 2;
	while (i < SIZE_POINT / 2)
	{
		j = -SIZE_POINT / 2;
		while (j < SIZE_POINT / 2)
		{
			my_pixel_put(win, x + j, y + i, 0x00ff00);
			j += 1;
		}
		i += 1;
	}
}

static int	put_map(t_win *win, t_plr *plr_data, char **map)
{
	int		x;
	int		y;

	x = plr_data->plr_pos_x / SCALE * SCALE_MAP;
	y = plr_data->plr_pos_y / SCALE * SCALE_MAP;
	put_point(win, plr_data, x, y);
	y = 0;
	while (y < plr_data->y_win)
	{
		x = 0;
		while (x < plr_data->x_win)
		{
			if (map[y][x] == '1')
				put_square(win, x * SCALE_MAP, y * SCALE_MAP, SCALE_MAP);
			++x;
		}
		++y;
	}
	return (0);
}

static int	put_player(t_win *win, t_plr *plr_data, char **map)
{
	double	angle;
	int		i;

	i = -1;
	angle = plr_data->plr_dir_rad + M_PI_2 / 3;
	while (++i < win->x_win)
	{
		init_cross(plr_data, angle);
		get_crossing(map, plr_data);
		get_distance(plr_data, i);
		plr_data->cross.wall_height = \
				round(win->y_win * SCALE / plr_data->cross.dist * win->prop);
		put_ray(win, plr_data->cross, i);
		angle -= M_PI / 3 / win->x_win;
	}
	put_map(win, plr_data, map);
	return (0);
}

void	put_screen(t_data *all)
{
	mlx_do_sync(all->win->mlx);
	put_player(all->win, all->plr_data, all->map);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
}
