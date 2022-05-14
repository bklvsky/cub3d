/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:09:04 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/13 21:09:24 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_plr_dir(char c, t_plr *plr_data)
{
	if (c == 'N')
		plr_data->plr_dir_rad = M_PI_2;
	else if (c == 'S')
		plr_data->plr_dir_rad = 3 * M_PI_2;
	else if (c == 'E')
		plr_data->plr_dir_rad = 0;
	else
		plr_data->plr_dir_rad = M_PI;
}
