/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:51:02 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/13 05:15:23 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_wall_side(t_crs cross)
{
	if (cross.type_cross == V_CROSS)
	{
		if (cos(cross.angle) > 0)
			return (EA_TEX);
		return (WE_TEX);
	}
	if (sin(cross.angle) > 0)
		return (NO_TEX);
	return (SO_TEX);
}
