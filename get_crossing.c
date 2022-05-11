/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_crossing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:49:10 by hashly            #+#    #+#             */
/*   Updated: 2022/05/11 15:40:30 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

// static void	find_nearest_cross(t_plr *data)
// {
// 	if (data->cross.h_cross_x == INIT_CROSS)
// 		data->cross.type_cross = V_CROSS;
// 	else if (data->cross.v_cross_x == INIT_CROSS)
// 		data->cross.type_cross = H_CROSS;
// 	else if (fabs(data->cross.v_cross_x - data->cross.h_cross_x) < 2.)
// 	{
// 		if (fabs(data->plr_pos_y - data->cross.h_cross_y) < fabs(data->plr_pos_y - data->cross.v_cross_y))
// 			data->cross.type_cross = H_CROSS;
// 		else
// 			data->cross.type_cross = V_CROSS;
// 	}
// 	else
// 	{
// 		if (fabs(data->plr_pos_x - data->cross.h_cross_x) < fabs(data->plr_pos_x - data->cross.v_cross_x))
// 			data->cross.type_cross = H_CROSS;
// 		else
// 			data->cross.type_cross = V_CROSS;
// 	}
// }

void	get_crossing(char **map, t_plr *data)
{
	// 	// printf("ANGLE = %f\n\tSTART  x = %f, y = %f\n", data->cross.angle * 180 / M_PI, data->plr_pos_x, data->plr_pos_y);
	// 	// fflush(stdout);
	// find_horiz_cross_wall(map, data);
	// 	// printf("\tHORIZ  x = %f, y = %f\n", data->cross.h_cross_x, data->cross.h_cross_y);
	// 	// fflush(stdout);
	// find_vertic_cross_wall(map, data);
	// find_nearest_cross(data);
	// 	// printf("\tVERTIC x = %f, y = %f\n", data->cross.v_cross_x, data->cross.v_cross_y);
	// 	// fflush(stdout);
	// if (data->cross.type_cross == V_CROSS) //vertic
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

	static	int	i = 0;
	static	int	j = 0;
	int	k = 0;
	double	step;
	
	step = START_STEP;
	while (map[(int)data->cross.y / SCALE][(int)data->cross.x / SCALE] != '1')
	{
		i++;
		k++;
		data->cross.x += data->cross.cos_angle * step;
		data->cross.y -= data->cross.sin_angle * step;
	}
	data->cross.x += data->cross.cos_angle * -step;
	data->cross.y -= data->cross.sin_angle * -step;
	step = FINISH_STEP;
	while (map[(int)data->cross.y / SCALE][(int)data->cross.x / SCALE] != '1')
	{
		i++;
		k++;
		data->cross.x += data->cross.cos_angle * step;
		data->cross.y -= data->cross.sin_angle * step;
	}
	if (fmod(round(data->cross.x), SCALE) < fmod(round(data->cross.y), SCALE))
		data->cross.type_cross = V_CROSS;
	else
		data->cross.type_cross = H_CROSS;
	j++;
	printf("line = %5d, proc in line = %5d, proc_sum = %d\n", j, k, i);
	printf("ANGLE = %f, x = %f, y = %f\n", data->cross.angle * 180 / M_PI, data->cross.x, data->cross.y);
	if (data->cross.type_cross == V_CROSS)
		printf("VERTIC\n");
	else
		printf("HORIZ\n\n");
	// fflush(stdout);
}
