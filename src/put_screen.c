/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:34:47 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/17 00:27:36 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	return (0);
}

void	put_screen(t_data *all)
{
	mlx_do_sync(all->win->mlx);
	put_player(all->win, all->plr_data, all->map);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
}
