/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:42:27 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/12 21:43:53 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_ceil(t_win *win, int x, int wall_st)
{
	int		y;

	y = 0;
	while (y != wall_st)
	{
		my_pixel_put(win, x, y, 0x00FFFFFF);
		y += 1;
	}
}

static void	put_wall(t_win *win, int x, int w_st, int w_end, int color)
{
	while (w_st != w_end)
	{
		my_pixel_put(win, x, w_st, color);
		w_st += 1;
	}
}

static void	put_floor(t_win *win, int x, int w_end)
{
	while (w_end != win->y_win)
	{
		my_pixel_put(win, x, w_end, 0x00D4D4D4);
		w_end += 1;
	}
}

void	put_ray(t_win *win, int w_color, int w_h, int x)
{
	int		wall_st;
	int		wall_end;

	wall_st = (win->y_win - w_h) / 2;
	wall_end = (win->y_win + w_h) / 2;
	if (wall_st < 0)
		wall_st = 0;
	if (wall_end > win->y_win)
		wall_end = win->y_win;
	put_ceil(win, x, wall_st);
	put_wall(win, x, wall_st, wall_end, w_color);
	put_floor(win, x, wall_end);
}
