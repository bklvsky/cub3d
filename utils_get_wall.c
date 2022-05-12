/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:51:02 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/11 20:21:38 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_wall_side(float y, float x, float ray_dir, char **map)
{
	if (map[(int)(y / SCALE)][(int)((x - cos(ray_dir) * 0.1) / SCALE)] == '0')
	{
		if (cos(ray_dir) > 0)
		{
			return EA_TEX;
		}
		return WE_TEX;
	}
	if (sin(ray_dir) > 0)
	{
		return NO_TEX;
	}
	return SO_TEX;
}
