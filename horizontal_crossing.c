/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_crossing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:25:03 by hashly            #+#    #+#             */
/*   Updated: 2022/05/11 15:27:57 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

// static void	find_first_horiz_cross(t_plr *data)
// {
// 	data->cross.len_y = SCALE;
// 	if (data->cross.sin_angle > 0.)
// 	{
// 		data->cross.len_y *= -1;
// 		data->cross.h_cross_y = (int)(data->plr_pos_y / SCALE) * SCALE - 1.;
// 	}
// 	else
// 		data->cross.h_cross_y = (int)(data->plr_pos_y / SCALE) * SCALE + SCALE;
// 	data->cross.h_cross_x = data->plr_pos_x + (data->plr_pos_y - data->cross.h_cross_y) / data->cross.tan_angle;
// 	data->cross.len_x = SCALE / data->cross.tan_angle;
// 	if (data->cross.cos_angle < 0. && data->cross.len_x > 0)
// 		data->cross.len_x *= -1;
// }

// static void	find_horiz_cross(t_plr *data)
// {
// 	double	error;
	
// 	data->cross.h_cross_x += data->cross.len_x;
// 	data->cross.h_cross_y += data->cross.len_y;
// 	error = fmod(round(data->cross.h_cross_y), SCALE); 
// 	while (error > 0.1)
// 	{
// 		data->cross.h_cross_x += data->cross.cos_angle * FINISH_STEP;
// 		data->cross.h_cross_y -= data->cross.sin_angle * FINISH_STEP;
// 		error = fmod(round(data->cross.h_cross_y), SCALE);
// 	}
// }

// void	find_horiz_cross_wall(char **map, t_plr *data)
// {
// 	if (fabs(data->cross.sin_angle) < 0.001)
// 		return ;
// 	find_first_horiz_cross(data);
// 	while (!wall(map, data, &data->cross.h_cross_x, &data->cross.h_cross_y))
// 		find_horiz_cross(data);
// }
