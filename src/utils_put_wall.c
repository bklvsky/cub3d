/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_put_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:48:14 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/17 00:22:01 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_x(t_img *tex, t_crs crs)
{
	if (crs.side == NO_TEX || crs.side == SO_TEX)
		return ((int)crs.x % SCALE * tex->width / SCALE);
	return ((int)crs.y % SCALE * tex->width / SCALE);
}

void	put_wall_texture(t_win *win, t_img *tex, int x, int wall_height)
{
	double			step;
	double			tex_y;
	int				wall_st;
	unsigned int	color;

	step = (double)tex->height / wall_height;
	wall_st = (win->y_win - wall_height) / 2;
	tex_y = 0;
	if (wall_st < 0)
	{
		wall_height = win->y_win;
		tex_y = -wall_st * step;
		wall_st = 0;
	}
	while (wall_height > 0)
	{
		color = *(unsigned int *) \
		(tex->addr + ((int)tex_y * tex->line_len + tex->x * (tex->bpp / 8)));
		my_pixel_put(win, x, wall_st, color);
		wall_height -= 1;
		wall_st += 1;
		tex_y += step;
	}
}
