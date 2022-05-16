/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:32:16 by hashly            #+#    #+#             */
/*   Updated: 2022/05/17 00:05:59 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	wall(char **map, t_plr *data, double *x0, double *y0)
{
	int	x;
	int	y;

	x = *x0 / SCALE;
	y = *y0 / SCALE;
	if (x < 0 || y < 0 || x > data->x_win - 1 || y > data->y_win - 1)
		return (1);
	if (map[y][x] != '1')
		return (1);
	return (0);
}

char	fill_correction(t_plr *plr_data, int x_win)
{
	int		i;
	double	angle;
	double	step;

	i = -1;
	angle = -M_PI_2 / 3.;
	step = (double)FOV_DEG / (double)(x_win - 1) / 180. * M_PI;
	plr_data->correction = ft_calloc(x_win, sizeof(double));
	if (!plr_data->correction)
		return (1);
	while (++i < x_win)
	{
		plr_data->correction[i] = cos(angle);
		angle += step;
	}
	return (0);
}

void	get_distance(t_plr *plr_data, int index)
{
	double	p_0;
	double	p_1;

	if (fabs(plr_data->cross.cos_angle) < 0.5)
	{
		p_0 = plr_data->plr_pos_y;
		p_1 = plr_data->cross.y;
		plr_data->cross.dist = fabs((p_1 - p_0) / plr_data->cross.sin_angle);
	}
	else
	{
		p_0 = plr_data->plr_pos_x;
		p_1 = plr_data->cross.x;
		plr_data->cross.dist = fabs((p_1 - p_0) / plr_data->cross.cos_angle);
	}
	plr_data->cross.dist *= plr_data->correction[index];
}
