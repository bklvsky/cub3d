/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_crossing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:49:10 by hashly            #+#    #+#             */
/*   Updated: 2022/05/11 00:42:44 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

// static double	dist(double x0, double y0, double x1, double y1)
// {
// 	return (sqrt(((y1 - y0) * (y1 - y0) + (x1 - x0) * (x1 - x0))));
// }

static void	find_nearest_cross(t_plr *data)
{
	if (data->cross.h_cross_x == INIT_CROSS)
		data->cross.type_cross = 1;
	else if (data->cross.v_cross_x == INIT_CROSS)
		data->cross.type_cross = 2;
	else if (fabs(data->cross.v_cross_x - data->cross.h_cross_x) < 2.)
	{
		if (fabs(data->plr_pos_y - data->cross.h_cross_y) < fabs(data->plr_pos_y - data->cross.v_cross_y))
			data->cross.type_cross = 2;
		else
			data->cross.type_cross = 1;
	}
	else
	{
		if (fabs(data->plr_pos_x - data->cross.h_cross_x) < fabs(data->plr_pos_x - data->cross.v_cross_x))
			data->cross.type_cross = 2;
		else
			data->cross.type_cross = 1;
	}
	// else if (dist(data->plr_pos_x, data->plr_pos_y, data->cross.v_cross_x, data->cross.v_cross_y) <
	// dist(data->plr_pos_x, data->plr_pos_y, data->cross.h_cross_x, data->cross.h_cross_y))
	// 	data->cross.type_cross = 1;
	// else
	// 	data->cross.type_cross = 2;
}

void	get_crossing(char **map, t_plr *data)
{
		// printf("ANGLE = %f\n\tSTART  x = %f, y = %f\n", data->cross.angle * 180 / M_PI, data->plr_pos_x, data->plr_pos_y);
		// fflush(stdout);
	find_horiz_cross_wall(map, data);
		// printf("\tHORIZ  x = %f, y = %f\n", data->cross.h_cross_x, data->cross.h_cross_y);
		// fflush(stdout);
	find_vertic_cross_wall(map, data);
	find_nearest_cross(data);
		// printf("\tVERTIC x = %f, y = %f\n", data->cross.v_cross_x, data->cross.v_cross_y);
		// fflush(stdout);
	// if (data->cross.type_cross == 1) //vertic
	// {
	// 	data->cross.x = data->cross.v_cross_x;
	// 	data->cross.y = data->cross.v_cross_y;
	// }
	// else //horiz
	// {
	// 	data->cross.x = data->cross.h_cross_x;
	// 	data->cross.y = data->cross.h_cross_y;
	// }
		// printf("\tFINISH x = %f, y = %f, type = %d\n", data->cross.x, data->cross.y, data->cross.type_cross);

	int	x;
	int	y;

	x = data->cross.x / SCALE;
	y = data->cross.y / SCALE;
	while (map[y][x] != '1')
	{
		data->cross.x += data->cross.cos_angle / SCALE;
		data->cross.y -= data->cross.sin_angle / SCALE;
		x = data->cross.x / SCALE;
		y = data->cross.y / SCALE;
	}

	// printf("ANGLE = %f, x = %f, y = %f\n\n", data->cross.angle * 180 / M_PI, data->cross.x, data->cross.y);
	// fflush(stdout);
}
