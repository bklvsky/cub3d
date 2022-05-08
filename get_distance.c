/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:32:16 by hashly            #+#    #+#             */
/*   Updated: 2022/05/09 02:03:01 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_correction(t_plr **plr_data)
{
	int	i;

	i = -1;
	while (++i <= NUM_BANDS)
		(*plr_data)->correction[i] = cos((i - NUM_BANDS / 2) * M_PI / 180.); // [-NUM_BANDS ; NUM_BANDS]
	// i = -1;
	// while (++i <= NUM_ANGLE_SET)
	// 	(*plr_data)->angle_set[i] = cos(i * 2 * M_PI / NUM_ANGLE_SET);
}

void	get_crossing(char **map, double	angle, double *x, double *y)
{
	// int		step;
	// double	b;
	// double	k;

	// k = tan(angle);
	// b = *y - k * *x;
	while (map[(int)*y / SCALE][(int)*x / SCALE] == '0' || map[(int)*y / SCALE][(int)*x / SCALE] == '2')
	{
		*y -= sin(angle) / SCALE; // деление - чтобы были меньше шаги
		*x += cos(angle) / SCALE; // деление - чтобы были меньше шаги
	}
}

double	get_distance(double x, double y, t_plr *plr_data, double angle)
{
	double	distance;
	double	x_0;
	double	y_0;
	int		index;

	x_0 = plr_data->plr_pos_x;
	y_0 = plr_data->plr_pos_y;
	distance = sqrt((y - y_0) * (y - y_0) + (x - x_0) * (x - x_0)); //slow
	// index = (angle / (2 * M_PI) * NUM_ANGLE_SET);
	// distance = fabs(fabs(x - x_0) / plr_data->angle_set[index]); //fast but while segfauit
	index = (angle - plr_data->plr_dir_rad + (NUM_BANDS / 2) * M_PI / 180) / M_PI * 180.;
	distance *= plr_data->correction[index];
	return (distance);
}
