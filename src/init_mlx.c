/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:18:29 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/18 11:08:40 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tex_img(void *mlx, char *path, t_img *tex)
{
	tex->img = mlx_xpm_file_to_image(mlx, path, &(tex->width), &(tex->height));
	if (!tex->img)
		return (put_error(path, ERR_STD));
	tex->addr = mlx_get_data_addr(tex->img, &(tex->bpp), \
									&(tex->line_len), &(tex->en));
	if (tex->width != tex->height)
		return (put_error(path, ERR_RESOLUTION));
	if (!tex->addr)
		return (put_error(path, ERR_STD));
	return (0);
}

static int	get_texture(t_win *win, t_config *cnfg)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (get_tex_img(win->mlx, cnfg->tex_paths[i], &(win->textures[i])) < 0)
			return (-1);
		i += 1;
	}
	return (0);
}

int	start_win(t_data *all)
{
	t_win	*win;

	win = all->win;
	win->mlx = mlx_init();
	if (!win->mlx)
		return (put_error(MLX_ERR, ERR_STD));
	mlx_get_screen_size(win->mlx, &(win->x_win), &(win->y_win));
	win->x_win /= NUM_MONITOR;
	if (fill_correction(all->plr_data, win->x_win))
		return (put_error(MLX_ERR, ERR_STD));
	win->prop = (double)win->x_win / (double)win->y_win;
	win->img = mlx_new_image(win->mlx, win->x_win, win->y_win);
	if (!win->img)
		return (put_error(MLX_ERR, ERR_STD));
	win->addr = mlx_get_data_addr(win->img, &(win->bpp), \
								&(win->line_len), &(win->en));
	if (!win->addr)
		return (put_error(MLX_ERR, ERR_STD));
	if (get_texture(win, all->cnfg) < 0)
		return (-1);
	win->win = mlx_new_window(win->mlx, win->x_win, win->y_win, "cub3d");
	if (!win->win)
		return (put_error(MLX_ERR, ERR_STD));
	return (0);
}
