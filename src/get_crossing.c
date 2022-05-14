/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_crossing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:49:10 by hashly            #+#    #+#             */
/*   Updated: 2022/05/13 18:29:05 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	get_crossing(char **map, t_plr *data)
{
	double	step;

	step = START_STEP;
	while (map[(int)data->cross.y / SCALE][(int)data->cross.x / SCALE] == '0')
	{
		data->cross.x += data->cross.cos_angle * step;
		data->cross.y -= data->cross.sin_angle * step;
	}
	data->cross.x += data->cross.cos_angle * -step;
	data->cross.y -= data->cross.sin_angle * -step;
	step = FINISH_STEP;
	while (map[(int)data->cross.y / SCALE][(int)data->cross.x / SCALE] == '0')
	{
		data->cross.x += data->cross.cos_angle * step;
		data->cross.y -= data->cross.sin_angle * step;
	}
	data->cross.side = get_wall_side(data->cross, map);
}
