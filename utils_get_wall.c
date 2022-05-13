/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:51:02 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/13 18:38:08 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ea_we_wall(double cos_angle)
{
	if (cos_angle > 0)
		return (EA_TEX);
	return (WE_TEX);
}

static int	no_so_wall(double sin_angle)
{
	if (sin_angle > 0)
		return (NO_TEX);
	return (SO_TEX);
}

int	get_wall_side(t_crs cross, char **map)
{
	if (map[(int)cross.y / SCALE][(int)(cross.x - \
							cross.cos_angle * FINISH_STEP) / SCALE] == '0')
		return (ea_we_wall(cross.cos_angle));
	return (no_so_wall(cross.sin_angle));
}
