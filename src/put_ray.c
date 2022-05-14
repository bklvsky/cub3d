/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:42:27 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/13 21:03:33 by dselmy           ###   ########.fr       */
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

static int	get_texture_x(t_img *tex, t_crs crs)
{
	if (crs.side == NO_TEX || crs.side == SO_TEX)
		return ((int)crs.x % SCALE * tex->width / SCALE);
	return ((int)crs.y % SCALE * tex->width / SCALE);
}

static void	put_wall_texture(t_win *win, t_img *tex, int x, int w_st, int w_end)
{
	double			step;
	double			tex_y;
	unsigned int	color;

	step = (double)tex->height / (w_end - w_st);
	tex_y = 0;
	if (w_st < 0)
	{
		tex_y = -w_st * step;
		w_st = 0;
		w_end = win->y_win;
	}
	while (w_st < w_end)
	{
		color = *(unsigned int *) \
		(tex->addr + ((int)tex_y * tex->line_len + tex->x * (tex->bpp / 8)));
		my_pixel_put(win, x, w_st, color);
		w_st += 1;
		tex_y += step;
	}
}

static void	put_wall(t_win *win, t_crs crs, int x, int wall_h)
{
	t_img	*tex;
	int		wall_st;
	int		wall_end;

	tex = win->textures + crs.side;
	wall_st = (win->y_win - wall_h) / 2;
	wall_end = (win->y_win + wall_h) / 2;
	tex->x = get_texture_x(tex, crs);
	put_wall_texture(win, tex, x, wall_st, wall_end);
}

static void	put_floor(t_win *win, int x, int w_end)
{
	while (w_end != win->y_win)
	{
		my_pixel_put(win, x, w_end, win->floor_color);
		w_end += 1;
	}
}

void	put_ray(t_win *win, t_crs crs, int w_h, int x)
{
	int		wall_st;
	int		wall_end;

	wall_st = (win->y_win - w_h) / 2;
	wall_end = (win->y_win + w_h) / 2;
	if (wall_st < 0)
		wall_st = 0;
	if (wall_end > win->y_win)
		wall_end = win->y_win;
	put_wall(win, crs, x, w_h);
	put_floor(win, x, wall_end);
	put_ceil(win, x, wall_st);
}
