/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:26:18 by dselmy            #+#    #+#             */
/*   Updated: 2021/08/06 02:06:39 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;
	
	dst = win->addr + (y * win->line_len + x * (win->bpp / 8));
	*(unsigned int*)dst = color;
}