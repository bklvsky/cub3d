/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:43:45 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/13 23:45:36 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_config(t_data *all)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		free(all->cnfg->tex_paths[i]);
		i += 1;
	}
	free(all->cnfg);
}

void	free_all(t_data *all)
{
	if (all->fd > 0)
		close(all->fd);
	free_config(all);
	free_arr(all->map);
	free(all->plr_data);
	free(all->win);
	free(all);
}
