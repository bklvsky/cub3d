/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:32:16 by hashly            #+#    #+#             */
/*   Updated: 2022/05/10 14:34:30 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char	find_mode(t_crs *data)
// {
// 	char	mode;

// 	if (data->cos_angle > 0.)
// 	{
// 		if (data->sin_angle > 0.)
// 			mode = 1;
// 		else if (data->sin_angle < 0.)
// 			mode = 7;
// 		else
// 			mode = 8;
// 	}
// 	else if (data->cos_angle < 0.)
// 	{
// 		if (data->sin_angle > 0.)
// 			mode = 3;
// 		else if (data->sin_angle < 0.)
// 			mode = 5;
// 		else
// 			mode = 4;
// 	}
// 	else
// 	{
// 		if (data->sin_angle > 0.)
// 			mode = 2;
// 		else
// 			mode = 6;
// 	}
// 	return (mode);
// }

// char	wall(char **map, char mode, double x0, double y0)
// {
// 	double	x;
// 	double	y;


// 	x = x0;
// 	y = y0;
// 	if (x < SCALE || y < SCALE)
// 		return (1);
// 	if (mode == 1 || mode == 2 || mode == 3)
// 		y = y - 1;
// 	else if (mode == 5 || mode == 6 || mode == 7)
// 		y = y + 1;
// 	if (mode == 3 || mode == 4 || mode == 5)
// 		x = x - 1;
// 	else if (mode == 1 || mode == 7 || mode == 8)
// 		x = x + 1;
// 	x = x / SCALE;
// 	y = y / SCALE;
// 	if (map[(int)y][(int)x] == '1')
// 		return (1);
// 	return (0);
// }

void	fill_correction(t_plr **plr_data)
{
	int	i;

	i = -1;
	while (++i <= NUM_BANDS)
		(*plr_data)->correction[i] = cos((i - NUM_BANDS / 2) * M_PI / 180.); // [-NUM_BANDS / 2 ; NUM_BANDS / 2]
	// i = -1;
	// while (++i <= NUM_ANGLE_SET)
	// {
	// 	(*plr_data)->angle_set_sin[i] = sin(i * 2 * M_PI / NUM_ANGLE_SET);
	// 	printf("i = %d, angle = %f, sin = %f\n", i, i * 2 * M_PI / NUM_ANGLE_SET * 180 / M_PI, (*plr_data)->angle_set_sin[i]);
	// }
}

void	get_distance(t_plr *plr_data)
{
	double	y_0;
	double	y_1;
	int		index;

	y_0 = plr_data->plr_pos_y;
	y_1 = plr_data->cross.y;
	// distance = sqrt((y - y_0) * (y - y_0) + (x - x_0) * (x - x_0)); //slow
	plr_data->cross.dist = fabs(y_1 - y_0) / fabs(plr_data->cross.sin_angle);
	index = (plr_data->cross.angle - plr_data->plr_dir_rad + NUM_BANDS * M_PI / 360) / M_PI * 180.;
	plr_data->cross.dist *= plr_data->correction[index];
}
