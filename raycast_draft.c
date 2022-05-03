/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:10:28 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/03 14:57:15 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	get_first_inters_y(double *x, double *y, double dir)
{
	while (((int)*y % SCALE) != 0)
	{
		*x += cos(dir);
		*y -= sin(dir);
	}
}

void	get_first_inters_x(double *x, double *y, double dir)
{
	while (((int)*x % SCALE) != 0)
	{
		*x += cos(dir);
		*y -= sin(dir);
	}
}

double	intersect_hor(char **map, double x_start, double y_start, double dir)
{
	double	delta_x;
	double	delta_y;
	double	x_end;
	double	y_end;

	delta_x = SCALE / tan(dir);
	delta_y = -SCALE;
	x_end = x_start;
	y_end = y_start;
	if (sin(dir) < 0)
	{
		delta_x = -delta_x;
		delta_y = -delta_y;
	}
	get_first_inters_y(&x_end, &y_end, dir);
	while (y_end >= 0 && x_end >= 0 && (map[(int)(y_end / SCALE)][(int)(x_end / SCALE)] == '0' || \
	map[(int)(y_end / SCALE)][(int)(x_end / SCALE)] == '2'))
	{
		printf("intersect_hor map[%d][%d]\n", (int)(y_end / SCALE), (int)(x_end / SCALE));
		y_end += delta_y;
		x_end += delta_x;
	}
	if (map[(int)(y_end / SCALE)][(int)((x_end - delta_x) / SCALE)] != '1')
		return (-1);
	return (fabs((y_start - y_end) / sin(dir)));
}

double	intersect_ver(char **map, double x_start, double y_start, double dir)
{
	double	delta_x;
	double	delta_y;
	double	x_end;
	double	y_end;

	delta_x = SCALE;
	delta_y = -SCALE * tan(dir);
	x_end = x_start;
	y_end = y_start;
	if (cos(dir) < 0)
	{
		delta_x = -delta_x;
		delta_y = -delta_y;
	}
	get_first_inters_x(&x_end, &y_end, dir);
	while (y_end >= 0 && x_end >= 0 && (map[(int)(y_end / SCALE)][(int)(x_end / SCALE)] == '0' || \
	map[(int)(y_end / SCALE)][(int)(x_end / SCALE)] == '2'))
	{
	//	printf("intersect_ver map[%d][%d]\n", (int)(y_end / SCALE), (int)(x_end / SCALE));
		y_end += delta_y;
		x_end += delta_x;
	}
	if (map[(int)((y_end - delta_y) / SCALE)][(int)(x_end / SCALE)] != '1')
		return (-1);
	return (fabs((x_start - x_end) / cos(dir)));
}
*/

void	get_intersect(char **map, double *x, double *y, double dir)
{
	double	delta_x;
	double	delta_y;
	
	delta_x = cos(dir);
	delta_y = -sin(dir);
	*x -= delta_x;
	*y -= delta_y;
	// *dist -= SCALE;
	while (map[(int)(*y / SCALE)][(int)(*x / SCALE)] == '0' || map[(int)(*y / SCALE)][(int)(*x / SCALE)] == '2')
	{
		*x += delta_x;
		*y += delta_y;
		// *dist += 1;
	}
}
/*
int		cast_ray(char **map, t_plr *plr, double dir, int *color)
{
	double	x;
	double	y;
	double	delta_x;
	double	delta_y;
	double	dist;
	
	y = plr->plr_pos_y;
	x = plr->plr_pos_x;
	delta_x = cos(dir);
	delta_y = -sin(dir);
	// double side_x = plr->pos_in_map_x * SCALE + SCALE - x;
	// double side_y = plr->pos_in_map_y * SCALE + SCALE - y;
	// dist = 0;
	while (map[(int)y / SCALE][(int)x / SCALE] == '0' || map[(int)y / SCALE][(int)x / SCALE] == '2')
	{
		y += delta_y;
		x += delta_x;
		// dist += SCALE;
	}
	get_intersect(map, &x, &y, dir);
	dist = sqrtf(powf(y - plr->plr_pos_y, 2) + powf(x - plr->plr_pos_x, 2));
	return (dist);
}
*/
/*double	drop_ray(char **map, t_plr *plr, double dir, int *color)
{
	double	dist_ver;
	double	dist_hor;

	dist_ver = intersect_ver(map, plr->plr_pos_x, plr->plr_pos_y, dir);
	dist_hor = intersect_hor(map, plr->plr_pos_x, plr->plr_pos_y, dir);
	printf("dist ver = %f dist hor = %f\n", dist_ver, dist_hor);
	if ((dist_ver < dist_hor && dist_ver >= 0) || dist_hor < 0)
	{
		*color = WALL_EA_WE;
		return (dist_ver);
	}
	else
	{
		*color = WALL_SO_NO;
		return (dist_hor);
	}
}*/


/*
int		raycast(char **map, t_plr *plr, t_win *win)
{
	double   ray_start;
	double   ray_end;
	int		wall_color;
	int		height;
	int		x;

	ray_start = plr->plr_dir_rad + M_PI_4;
	ray_end = plr->plr_dir_rad - M_PI_4;
	x = 0;
	while (ray_start >= ray_end)
	{
		float dist = cast_ray(map, plr, ray_start, &wall_color);
		height = win->y_win * SCALE  / dist / cos(plr->plr_dir_rad - ray_start);
		// exit(0);
		// printf("%f\n", dist);
		put_ray(win, wall_color, height, x);
		ray_start -= M_PI_2 / win->x_win;
		x += 1;
	}
	return (0);
}*/
