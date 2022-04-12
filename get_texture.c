/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:40:23 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/13 00:52:49 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tex_img(void *mlx, char *path, t_img *tex)
{
	tex->img = mlx_xpm_file_to_image(mlx, path, &(tex->width), &(tex->height));
	if (!tex->img)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img, &(tex->bpp), \
									&(tex->line_len), &(tex->en));
	if (!tex->addr)
		return (0);
	return (1);
}

int	get_texture(t_win *win, t_config *cnfg)
{
	if (get_tex_img(win->mlx, cnfg->no_tex_path, &(win->no_tex)) | \
			get_tex_img(win->mlx, cnfg->so_tex_path, &(win->so_tex)) | \
			get_tex_img(win->mlx, cnfg->we_tex_path, &(win->we_tex)) | \
			get_tex_img(win->mlx, cnfg->ea_tex_path, &(win->ea_tex)))
		return (-1);
	return (0);
}
