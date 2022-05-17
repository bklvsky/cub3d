/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:06:36 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/18 00:21:55 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_plr(char **map, t_plr *plr_data, double step_y, double step_x)
{
	double	y;
	double	x;

	y = plr_data->plr_pos_y + step_y;
	x = plr_data->plr_pos_x + step_x;
	if (map[(int)((y + step_y * 5) / SCALE)][(int)((x + step_x * 5) / SCALE)] \
																		!= '1')
	{
		plr_data->plr_pos_y = y;
		plr_data->plr_pos_x = x;
	}
}

void	plr_up(char **map, t_plr *plr_data)
{
	double	step_y;
	double	step_x;

	step_x = cos(plr_data->plr_dir_rad) * PLR_SPEED;
	step_y = -(sin(plr_data->plr_dir_rad) * PLR_SPEED);
	move_plr(map, plr_data, step_y, step_x);
}

void	plr_down(char **map, t_plr *plr_data)
{
	double	step_y;
	double	step_x;

	step_x = -(cos(plr_data->plr_dir_rad) * PLR_SPEED);
	step_y = sin(plr_data->plr_dir_rad) * PLR_SPEED;
	move_plr(map, plr_data, step_y, step_x);
}

void	plr_left(char **map, t_plr *plr_data)
{
	double	step_y;
	double	step_x;

	step_x = -(sin(plr_data->plr_dir_rad) * PLR_SPEED);
	step_y = -(cos(plr_data->plr_dir_rad) * PLR_SPEED);
	move_plr(map, plr_data, step_y, step_x);
}

void	plr_right(char **map, t_plr *plr_data)
{
	double	step_y;
	double	step_x;

	step_x = sin(plr_data->plr_dir_rad) * PLR_SPEED;
	step_y = cos(plr_data->plr_dir_rad) * PLR_SPEED;
	move_plr(map, plr_data, step_y, step_x);
}
