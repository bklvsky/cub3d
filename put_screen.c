/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:34:47 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/13 20:44:29 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_raycast(t_win *win, t_crs crs, int win_x)
{
	int	wall_height;

	if (win_x < win->x_win)
	{
		wall_height = round(win->y_win * SCALE / crs.dist * win->prop);
		put_ray(win, crs, round(wall_height), win_x);
	}
}

static int	put_player(t_win *win, t_plr *plr_data, char **map)
{
	double	angle;
	int		i;

	i = 0;
	angle = plr_data->plr_dir_rad + M_PI_2 / 3;
	while (angle >= plr_data->plr_dir_rad - M_PI_2 / 3)
	{
		init_cross(plr_data, angle);
		get_crossing(map, plr_data);
		get_distance(plr_data);
		put_raycast(win, plr_data->cross, i);
		i += 1;
		angle -= M_PI / 3 / win->x_win;
	}
	return (0);
}

void	put_screen(t_data *all)
{
	mlx_do_sync(all->win->mlx);
	put_player(all->win, all->plr_data, all->map);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
}
