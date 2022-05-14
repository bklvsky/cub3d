/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:06:36 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/13 20:20:51 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	plr_up(char **map, t_plr *plr_data)
{
	double	y;
	double	x;

	y = plr_data->plr_pos_y - sin(plr_data->plr_dir_rad) * PLR_SPEED;
	x = plr_data->plr_pos_x + cos(plr_data->plr_dir_rad) * PLR_SPEED;
	if (map[(int)(y / SCALE)][(int)(x / SCALE)] != '1')
	{
		plr_data->plr_pos_y = y;
		plr_data->plr_pos_x = x;
	}
}

void	plr_down(char **map, t_plr *plr_data)
{
	double	y;
	double	x;

	y = plr_data->plr_pos_y + sin(plr_data->plr_dir_rad) * PLR_SPEED;
	x = plr_data->plr_pos_x - cos(plr_data->plr_dir_rad) * PLR_SPEED;
	if (map[(int)(y / SCALE)][(int)(x / SCALE)] != '1')
	{
		plr_data->plr_pos_y = y;
		plr_data->plr_pos_x = x;
	}
}

void	plr_left(char **map, t_plr *plr_data)
{
	double	y;
	double	x;

	y = plr_data->plr_pos_y - cos(plr_data->plr_dir_rad) * PLR_SPEED;
	x = plr_data->plr_pos_x - sin(plr_data->plr_dir_rad) * PLR_SPEED;
	if (map[(int)(y / SCALE)][(int)(x / SCALE)] != '1')
	{
		plr_data->plr_pos_y = y;
		plr_data->plr_pos_x = x;
	}
}

void	plr_right(char **map, t_plr *plr_data)
{
	double	y;
	double	x;

	y = plr_data->plr_pos_y + cos(plr_data->plr_dir_rad) * PLR_SPEED;
	x = plr_data->plr_pos_x + sin(plr_data->plr_dir_rad) * PLR_SPEED;
	if (map[(int)(y / SCALE)][(int)(x / SCALE)] != '1')
	{
		plr_data->plr_pos_y = y;
		plr_data->plr_pos_x = x;
	}
}
