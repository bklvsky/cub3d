/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:18:29 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/13 18:48:47 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	put_error(char *path)
{
	ft_putstr_fd("MLX error\n", 2);
	if (path)
		perror(path);
	else
		perror("");
	return (-1);
}

static int	get_tex_img(void *mlx, char *path, t_img *tex)
{
	tex->img = mlx_xpm_file_to_image(mlx, path, &(tex->width), &(tex->height));
	if (!tex->img)
		return (put_error(path));
	tex->addr = mlx_get_data_addr(tex->img, &(tex->bpp), \
									&(tex->line_len), &(tex->en));
	if (!tex->addr)
		return (put_error(path));
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

int	start_win(t_win *win, t_config *cnfg)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		return (put_error(NULL));
	mlx_get_screen_size(win->mlx, &(win->x_win), &(win->y_win));
	win->prop = (double)win->x_win / (double)win->y_win;
	win->img = mlx_new_image(win->mlx, win->x_win, win->y_win);
	if (!win->img)
		return (put_error(NULL));
	win->addr = mlx_get_data_addr(win->img, &(win->bpp), \
								&(win->line_len), &(win->en));
	if (!win->addr)
		return (put_error(NULL));
	if (get_texture(win, cnfg) < 0)
		return (-1);
	win->win = mlx_new_window(win->mlx, win->x_win, win->y_win, "cub3d");
	if (!win->win)
		return (put_error(NULL));
	return (0);
}
