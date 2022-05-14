/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 02:12:40 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/15 01:59:52 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	stop_game(t_data *all)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (all->win->textures[i].img)
			mlx_destroy_image(all->win->mlx, all->win->textures[i].img);
		i += 1;
	}
	if (all->win->img)
		mlx_destroy_image(all->win->mlx, all->win->img);
	if (all->win->win)
		mlx_destroy_window(all->win->mlx, all->win->win);
	shut_down(all);
	return (0);
}

void	shut_down(t_data *all)
{
	if (all)
		free_all(all);
	exit(0);
}
