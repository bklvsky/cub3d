/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 01:43:54 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/11 23:46:35 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_win(t_win **win)
{
	*win = ft_calloc(1, sizeof(t_win));
	if (!(*win))
		return (ERR_STD);
	return (0);
}

int		init_config(t_config **cnfg)
{
	*cnfg = ft_calloc(1, sizeof(t_config));
	if (!(*cnfg))
		return (ERR_STD);
	return (0);
}

int		init_plr(t_plr	**plr_data)
{
	if (!(*plr_data = (t_plr *)malloc(sizeof(t_plr))))
		return (ERR_STD);
	(*plr_data)->plr_num = 0;
	(*plr_data)->plr_pos_x = -1;
	(*plr_data)->plr_pos_y = -1;
	(*plr_data)->plr_dir_rad = M_PI_2;
	fill_correction(plr_data);
	return (0);
}

int		init_struct(t_data *all)
{
	int		error;

	error = 0;
	all->fd = -1;
	all->map = NULL;
	if ((error = init_win(&(all->win))) != 0)
		return (error);
	if ((error = init_config(&(all->cnfg))) != 0)
		return (error);
	all->cnfg->ceil_color = &(all->win->ceil_color);
	all->cnfg->floor_color = &(all->win->floor_color);
	if ((error = init_plr(&(all->plr_data))) != 0)
		return (error);
	return (error);
}

void	init_cross(t_plr *plr, double angle)
{
	plr->cross.angle = angle;
	plr->cross.sin_angle = sin(angle);
	plr->cross.cos_angle = cos(angle);
	plr->cross.x = plr->plr_pos_x;
	plr->cross.y = plr->plr_pos_y;
	plr->cross.dist = -1;
	plr->cross.type_cross = 0;
}
