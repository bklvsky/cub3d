/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_crossing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:27:39 by hashly            #+#    #+#             */
/*   Updated: 2022/05/11 15:28:01 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	find_first_vertic_cross(t_plr *data)
// {
// 	data->cross.len_x = SCALE;
// 	if (data->cross.cos_angle < 0.)
// 	{
// 		data->cross.len_x = -SCALE;
// 		data->cross.v_cross_x = (int)(data->plr_pos_x / SCALE) * SCALE - 1.;
// 	}
// 	else
// 		data->cross.v_cross_x = (int)(data->plr_pos_x / SCALE) * SCALE + SCALE;
// 	data->cross.v_cross_y = data->plr_pos_y + (data->plr_pos_x - data->cross.v_cross_x) * data->cross.tan_angle;
// 	data->cross.len_y = SCALE * data->cross.tan_angle;
// 	if (data->cross.sin_angle > 0. && data->cross.len_y > 0.)
// 		data->cross.len_y *= -1;
// }

// static void	find_vertic_cross(t_plr *data)
// {
// 	double	error;
	
// 	data->cross.v_cross_x += data->cross.len_x;
// 	data->cross.v_cross_y += data->cross.len_y;
// 	error = fmod(round(data->cross.v_cross_x), SCALE);
// 	while (error > 0.1)
// 	{
// 		data->cross.v_cross_x += data->cross.cos_angle * FINISH_STEP;
// 		data->cross.v_cross_y -= data->cross.sin_angle * FINISH_STEP;
// 		error = fmod(round(data->cross.v_cross_x), SCALE);
// 	}
// }

// void	find_vertic_cross_wall(char **map, t_plr *data)
// {
// 	if (fabs(data->cross.cos_angle) < 0.001)
// 		return ;
// 	find_first_vertic_cross(data);
// 	while (!wall(map, data, &data->cross.v_cross_x, &data->cross.v_cross_y))
// 		find_vertic_cross(data);
// }
