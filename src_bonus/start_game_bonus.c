/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:07:58 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/18 18:21:59 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	mouse_press(int button, int x, int y, void *param)
{
	t_data	*data;

	if (button != 1 || y < -100)
		return (0);
	data = param;
	data->plr_data->x_press = x;
	return (0);
}

static int	mouse_release(int button, int x, int y, void *param)
{
	t_data	*all;
	double	diff;
	double	angle;

	if (button != 1 || y < -100)
		return (0);
	all = param;
	diff = all->plr_data->x_press - x;
	angle = fabs(diff) * M_PI / 3. / all->win->x_win;
	while (angle > 0.)
	{
		if (diff > 0.)
			plr_rot_left(all->plr_data);
		else if (diff < 0.)
			plr_rot_right(all->plr_data);
		put_screen(param);
		angle -= PLR_SPEED_TURN;
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
	mlx_hook(all->win->win, 4, (1L << 2), mouse_press, all);
	mlx_hook(all->win->win, 5, (1L << 3), mouse_release, all);
	mlx_loop(all->win->mlx);
	return (0);
}
