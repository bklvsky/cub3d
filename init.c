/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 01:43:54 by dselmy            #+#    #+#             */
/*   Updated: 2021/08/06 00:04:00 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_win(t_win **win)
{
	if (!(*win = (t_win *)malloc(sizeof(t_win))))
		return (ERR_STD);
	/*(*win)->mlx = NULL;
	(*win)->win = NULL;
	(*win)->img = NULL;
	(*win)->addr = NULL;*/
	return (0);
}

int		init_config(t_config **cnfg)
{
	int		i;

	i = -1;
//	printf("init_config\n");
	if (!(*cnfg = (t_config *)malloc(sizeof(t_config))))
		return (ERR_STD);
	else
	{
		while (++i <= 9)
			(*cnfg)->data[i] = 0;
//		printf("set data[]\n");
		/*(*cnfg)->x_res = -1;
		(*cnfg)->y_res = -1;
		(*cnfg)->ceil_color = -1;
		(*cnfg)->floor_color = -1;*/
		(*cnfg)->no_tex_path = NULL;
		(*cnfg)->so_tex_path = NULL;
		(*cnfg)->ea_tex_path = NULL;
		(*cnfg)->we_tex_path = NULL;
		(*cnfg)->spr_tex_path = NULL;
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