/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:32:16 by hashly            #+#    #+#             */
/*   Updated: 2022/05/14 17:31:51 by hashly           ###   ########.fr       */
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

void	fill_correction(t_plr **plr_data)
{
	int	i;

	i = -1;
	while (++i <= NUM_BANDS)
		(*plr_data)->correction[i] = cos((i - NUM_BANDS / 2) * M_PI / 180.);
}

void	get_distance(t_plr *plr_data)
{
	double	pnt_0;
	double	pnt_1;
	int		index;

	if (fabs(plr_data->cross.cos_angle) < 0.5)
	{
		pnt_0 = plr_data->plr_pos_y;
		pnt_1 = plr_data->cross.y;
		plr_data->cross.dist = fabs((pnt_1 - pnt_0) / plr_data->cross.sin_angle);
	}
	else
	{
		pnt_0 = plr_data->plr_pos_x;
		pnt_1 = plr_data->cross.x;
		plr_data->cross.dist = fabs((pnt_1 - pnt_0) / plr_data->cross.cos_angle);
	}
	index = (plr_data->cross.angle - plr_data->plr_dir_rad + \
										NUM_BANDS * M_PI / 360) / M_PI * 180.;
	plr_data->cross.dist *= plr_data->correction[index];
}
