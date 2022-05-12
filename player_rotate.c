/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:09:44 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/12 05:11:47 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	normalize_plr_direction(t_plr *plr_data)
{
	if (plr_data->plr_dir_rad >= 2 * M_PI)
		plr_data->plr_dir_rad -= 2 * M_PI;
	else if (plr_data->plr_dir_rad < 0)
		plr_data->plr_dir_rad += 2 * M_PI;
}

void	plr_rot_right(t_plr *plr_data)
{
	plr_data->plr_dir_rad -= 0.05;
	normalize_plr_direction(plr_data);
}

void	plr_rot_left(t_plr *plr_data)
{
	plr_data->plr_dir_rad += 0.05;
	normalize_plr_direction(plr_data);
}
