/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:07:58 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/13 11:00:22 by hashly           ###   ########.fr       */
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

static int	mouse_hook(int x, int y, void *param)
{
	t_data	*all;
	int		x_new;

	all = param;
	x_new = all->win->x_win / 2;
	if (x - x_new > 10)
	{
		// x_new = all->win->x_win / 2 - 50;
		plr_rot_right(all->plr_data);
		mlx_mouse_move(all->win->mlx, all->win->win, x_new, y);
		put_screen(param);
	}
	else if (x - x_new < -10)
	{
		plr_rot_left(all->plr_data);
		mlx_mouse_move(all->win->mlx, all->win->win, x_new, y);
		put_screen(param);
	}
	return (0);
}

int		cub(t_data *all)
{
	if (start_win(all->win, all->cnfg) < 0)
		return (-1); // error management
	// put_map(all->win, all->cnfg, all->map);
	all->plr_data->x_win = all->map_width;
	all->plr_data->y_win = all->map_h;
	put_screen(all);
	mlx_mouse_hide(all->win->mlx, all->win->win);
	mlx_hook(all->win->win, 2, (1L<<0), &key_handle, all);
	mlx_hook(all->win->win, 17, (1L<<17), stop_game, all);
	mlx_hook(all->win->win, 6, (1L<<6), mouse_hook, all);
	mlx_loop(all->win->mlx);
	return (0);
}