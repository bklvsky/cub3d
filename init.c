/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 01:43:54 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/10 15:01:26 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_win(t_win **win)
{
	if (!(*win = (t_win *)malloc(sizeof(t_win))))
		return (ERR_STD);
	return (0);
}

int		init_config(t_config **cnfg)
{
	int		i;

	i = -1;
	if (!(*cnfg = (t_config *)malloc(sizeof(t_config))))
		return (ERR_STD);
	else
	{
		while (++i < SIZE_DATA)
			(*cnfg)->data[i] = 0;
		(*cnfg)->no_tex_path = NULL;
		(*cnfg)->so_tex_path = NULL;
		(*cnfg)->ea_tex_path = NULL;
		(*cnfg)->we_tex_path = NULL;
	}
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

//	printf("init struct\n");
	error = 0;
	all->fd = -1;
	all->map = NULL;
	if ((error = init_config(&(all->cnfg))) != 0)
		return (error);
	if ((error = init_plr(&(all->plr_data))) != 0)
		return (error);
	if ((error = init_win(&(all->win))) != 0)
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
	// plr->cross.k = -tan(angle);
	// plr->cross.b = *y - data.k * *x;
	plr->cross.h_cross_x = -1;
	plr->cross.h_cross_y = -1;
	plr->cross.v_cross_x = -1;
	plr->cross.v_cross_y = -1;
	plr->cross.len_x = START_STEP;
	plr->cross.len_y = START_STEP;
	// plr->cross.mode = find_mode(&data);
}
