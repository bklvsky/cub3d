/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:07:58 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/16 23:47:27 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub(t_data *all)
{
	if (start_win(all) < 0)
		stop_game(all);
	all->plr_data->x_win = all->map_width;
	all->plr_data->y_win = all->map_h;
	put_screen(all);
	mlx_hook(all->win->win, 2, (1L << 0), &key_handle, all);
	mlx_hook(all->win->win, 17, (1L << 17), stop_game, all);
	mlx_loop(all->win->mlx);
	return (0);
}
