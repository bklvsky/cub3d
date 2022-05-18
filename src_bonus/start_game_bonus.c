/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:07:58 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/18 15:32:50 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	mouse_hook(int x, int y, void *param)
{
	t_data	*all;
	int		x_new;
	int		a;

	all = param;
	a = 30;
	x_new = all->win->x_win / 2;
	if (x - x_new > a)
	{
		plr_rot_right(all->plr_data);
		mlx_mouse_move(all->win->mlx, all->win->win, x_new, y);
		put_screen(param);
	}
	else if (x - x_new < -a)
	{
		plr_rot_left(all->plr_data);
		mlx_mouse_move(all->win->mlx, all->win->win, x_new, y);
		put_screen(param);
	}
	return (0);
}

int	cub(t_data *all)
{
	if (start_win(all) < 0)
		stop_game(all);
	all->plr_data->x_win = all->map_width;
	all->plr_data->y_win = all->map_h;
	put_screen(all);
	mlx_hook(all->win->win, 2, (1L << 0), &key_handle, all);
	mlx_hook(all->win->win, 17, (1L << 17), stop_game, all);
	mlx_mouse_hide(all->win->mlx, all->win->win);
	mlx_hook(all->win->win, 6, (1L << 6), mouse_hook, all);
	mlx_loop(all->win->mlx);
	return (0);
}
