/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:51:02 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/03 15:09:30 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_wall_side(float y, float x, float ray_dir, char **map)
{
	if (map[(int)(y / SCALE)][(int)((x - cos(ray_dir) * 0.1) / SCALE)] == '0')
	{
		if (cos(ray_dir) > 0)
			return COLOR_EA;
		return COLOR_WE;
	}
	if (sin(ray_dir) > 0)
		return COLOR_NO;
	return COLOR_SO;
}
