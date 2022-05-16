/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:42:27 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/17 02:52:55 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_ceil(t_win *win, int x, int wall_st)
{
	int		y;

	y = 0;
	while (y != wall_st)
	{
		my_pixel_put(win, x, y, win->ceil_color);
		y += 1;
	}
}

static void	put_wall(t_win *win, t_crs crs, int x)
{
	t_img	*tex;

	tex = win->textures + crs.side;
	tex->x = get_texture_x(tex, crs);
	put_wall_texture(win, tex, x, crs);
}

static void	put_floor(t_win *win, int x, int w_end)
{
	while (w_end != win->y_win)
	{
		my_pixel_put(win, x, w_end, win->floor_color);
		w_end += 1;
	}
}

void	put_ray(t_win *win, t_crs crs, int x)
{
	int		wall_st;
	int		wall_end;

	wall_st = (win->y_win - crs.wall_height) / 2;
	wall_end = wall_st + crs.wall_height;
	if (wall_st < 0)
		wall_st = 0;
	if (wall_end > win->y_win)
		wall_end = win->y_win;
	put_wall(win, crs, x);
	put_floor(win, x, wall_end);
	put_ceil(win, x, wall_st);
}
