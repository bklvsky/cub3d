/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 23:10:28 by dselmy            #+#    #+#             */
/*   Updated: 2021/08/17 02:50:23 by dselmy           ###   ########.fr       */
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

void	get_intersect(char **map, double *x, double *y, double dir, int *dist)
{
	double	delta_x;
	double	delta_y;
	
	delta_x = cos(dir);
	delta_y = -sin(dir);
	*x -= delta_x * SCALE;
	*y -= delta_y * SCALE;
	*dist -= SCALE;
//	printf("in get intersect");
	while (map[(int)(*y / SCALE)][(int)(*x / SCALE)] == '0' || map[(int)(*y / SCALE)][(int)(*x / SCALE)] == '2')
	{
//		printf("x = %f, y = %f\n", *x, *y);
		*x += delta_x;
		*y += delta_y;
		*dist += 1;
	}
}

void	get_side_no_so(int *color, double dir)
{
	if (sin(dir) > 0)
		*color = COLOR_SO;
	else
		*color = COLOR_NO;
}

void	get_side_ea_we(int *color, double dir)
{
	if (cos(dir) > 0)
		*color = COLOR_WE;
	else
		*color = COLOR_EA;
}

int		cast_ray(char **map, t_plr *plr, double dir, int *color)
{
	double	x;
	double	y;
	double	delta_x;
	double	delta_y;
	int		dist;
	
	y = plr->plr_pos_y;
	x = plr->plr_pos_x;
	delta_x = SCALE * cos(dir);
	delta_y = -SCALE * sin(dir);
	dist = 0;
//	printf("in cast ray\n");
	printf("cos(dir) = %f sin(dir) = %f\n", cos(dir), sin(dir));
//	while ((int)(x / SCALE) >= 0 && (int)(y / SCALE) && (map[(int)(y / SCALE)][(int)(x / SCALE)] == '0' || map[(int)(y / SCALE)][(int)(x / SCALE)] == '2'))
	while (map[(int)(y / SCALE)][(int)(x / SCALE)] == '0' || map[(int)(y / SCALE)][(int)(x / SCALE)] == '2')
	{
		y += delta_y;
		x += delta_x;
		dist += SCALE;
	//	printf("map[%d][%d]\n", (int)(y / SCALE), (int)(x / SCALE));
	//	printf("y = %f, x = %f\n", y, x);
	}
	get_intersect(map, &x, &y, dir, &dist);
//	printf("intersection: x %f y %f\n", x, y);
	if (map[(int)(y / SCALE)][(int)((x - delta_x) / SCALE)] == '1')
		get_side_no_so(color, dir);
	else
		get_side_ea_we(color, dir);
	return (dist);
}

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

void	put_ceil(t_win *win, int x, int wall_st)
{
	int		y;

	y = 0;
	while (y != wall_st)
	{
		my_pixel_put(win, x, y, 0x00FFFFFF);
		y += 1;
	}
}

void	put_wall(t_win *win, int x, int w_st, int w_end, int color)
{
	while (w_st != w_end)
	{
		my_pixel_put(win, x, w_st, color);
		w_st += 1;
	}
}

void	put_floor(t_win *win, int x, int w_end)
{
	while (w_end != win->y_win)
	{
		my_pixel_put(win, x, w_end, 0x00D4D4D4);
		w_end += 1;
	}
}

void	put_ray(t_win *win, int w_color, int w_h, int x)
{
	int		wall_st;
	int		wall_end;

	printf("in put ray, height = %d win_y = %d\n", w_h, win->y_win);
	wall_st = (win->y_win - w_h) / 2;
	wall_end = (win->y_win + w_h) / 2;
	if (wall_st < 0)
		wall_st = 0;
	if (wall_end > win->y_win)
		wall_end = win->y_win;
	put_ceil(win, x, wall_st);
	put_wall(win, x, wall_st, wall_end, w_color);
	put_floor(win, x, wall_end);
}

int		raycast(char **map, t_plr *plr, t_win *win)
{
	double   ray_start;
	double   ray_end;
	int		wall_color;
	int		height;
	int		x;

//	printf("in raycast\n");
	ray_start = plr->plr_dir_rad + M_PI_4;
	ray_end = plr->plr_dir_rad - M_PI_4;
	x = 0;
//	printf("plr y = %f, plr x = %f\n", plr->plr_pos_y / SCALE, plr->plr_pos_x / SCALE);
	while (ray_start >= ray_end)
	{
	//	printf("number %d\n", x);
		height = win->y_win * SCALE  / cast_ray(map, plr, ray_start, &wall_color) / fabs(cos(plr->plr_dir_rad - ray_start));
	//	printf("height = %f\n", height);
	//	height = win->y_win * SCALE / drop_ray(map, plr, ray_start, &wall_color) / fabs(cos(plr->plr_dir_rad - ray_start));
		put_ray(win, wall_color, height, x);
	//	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
		ray_start -= M_PI_2 / win->x_win;
		x += 1;
	}
	return (0);
}