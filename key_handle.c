/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:27:14 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/12 16:58:38 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handle(int key, t_data *all)
{
	if (key == KEY_UP || key == KEY_W)
		plr_up(all->map, all->plr_data);
	if (key == KEY_DOWN || key == KEY_S)
		plr_down(all->map, all->plr_data);
	if (key == KEY_A)
		plr_left(all->map, all->plr_data);
	if (key == KEY_D)
		plr_right(all->map, all->plr_data);
	if (key == KEY_LEFT)
		plr_rot_left(all->plr_data);
	if (key == KEY_RIGHT)
		plr_rot_right(all->plr_data);
	if (key == KEY_ESC)
		stop_game(all);
	put_screen(all);
	return(0);
}
