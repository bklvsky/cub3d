/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:32:16 by hashly            #+#    #+#             */
/*   Updated: 2022/05/13 10:41:05 by hashly           ###   ########.fr       */
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
		(*plr_data)->correction[i] = cos((i - NUM_BANDS / 2.) * M_PI / 180.);
}

void	get_distance(t_plr *plr_data)
{
	double	y_0;
	double	y_1;
	int		index;

	y_0 = plr_data->plr_pos_y;
	y_1 = plr_data->cross.y;
	plr_data->cross.dist = fabs(y_1 - y_0) / fabs(plr_data->cross.sin_angle);
	index = (plr_data->cross.angle - plr_data->plr_dir_rad + NUM_BANDS * M_PI / 360) / M_PI * 180.;
	plr_data->cross.dist *= plr_data->correction[index];
}
