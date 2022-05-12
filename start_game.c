/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:07:58 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/12 04:55:19 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* for debug purpose

void	print_arr(char **arr)
{
	int		y;

	y = 0;
	while (arr[y])
	{
		printf("%d %s\n", y, arr[y]);
		y += 1;
	}
}

void	print_config(t_config *cnfg, char **map)
{
	print_arr(map);
	printf("x_res = %d\n", cnfg->x_res);
	printf("y_res = %d\n", cnfg->y_res);
	printf("no_tex_path = %s\n", cnfg->no_tex_path);
	printf("so_tex_path = %s\n", cnfg->so_tex_path);
	printf("ea_tex_path = %s\n", cnfg->ea_tex_path);
	printf("we_tex_path = %s\n", cnfg->we_tex_path);
}

*/

int		cub(t_data *all)
{
	if (start_win(all->win, all->cnfg) < 0)
		return (-1); // error management
	// put_map(all->win, all->cnfg, all->map);
	all->plr_data->x_win = all->map_width;
	all->plr_data->y_win = all->map_h;
	put_screen(all);
	mlx_hook(all->win->win, 2, (1L<<0), &key_handle, all);
	mlx_hook(all->win->win, 17, (1L<<17), stop_game, all);
	mlx_loop(all->win->mlx);
	return (0);
}
