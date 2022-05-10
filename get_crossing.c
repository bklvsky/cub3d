/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_crossing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:49:10 by hashly            #+#    #+#             */
/*   Updated: 2022/05/10 15:04:37 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

// static void	find_horiz_cross(t_crs *data)
// {
// 	if (fabs(data->cos_angle) > 0.0001)
// 	{
// 		if (fabs(data->len_x) < 1.)
// 			data->h_cross_x += data->len_x * PROD_STEP;
// 		else
// 			data->h_cross_x += data->len_x;
// 		data->h_cross_y = data->k * data->h_cross_x + data->b;
// 	}
// 	else if (data->sin_angle > 0.) //up
// 	{
// 		printf("UP\n");
// 		fflush(stdout);
// 		data->h_cross_y -= data->len_y;
// 	}
// 	else //down
// 		data->h_cross_y += data->len_y;
// 	while (fabs(fmod(data->h_cross_y, SCALE)) > BAND)
// 	{
// 		if (fabs(data->cos_angle) > 0.0001)
// 		{
// 			data->h_cross_x += data->len_x;
// 			data->h_cross_y = data->k * data->h_cross_x + data->b;
// 		}
// 		else if (data->sin_angle > 0) //up
// 			data->h_cross_y -= data->len_y;
// 		else //down
// 			data->h_cross_y += data->len_y;
// 	}
// }

// static void	find_horiz_cross_wall(char **map, t_crs *data, double *x, double *y)
// {
// 	double	temp;

// 	if (data->sin_angle == 0.)
// 		return ;
// 	if (data->cos_angle > 0.)
// 		data->len_x = START_STEP;
// 	else
// 		data->len_x = -START_STEP;
// 	data->len_y = START_STEP;
// 	data->h_cross_x = *x;
// 	data->h_cross_y = *y;
// 	// printf("start angle = %f\n", data->angle * 180 / M_PI);
// 	printf("b = %f; k = %f\n", data->b, data->k);
// 	// printf("start pnt x = %f, y = %f\n", data->cross_x, data->cross_y);
// 	// fflush(stdout);
// 	find_horiz_cross(data); //replace cross_x cross_y
// 	// printf("first_horiz cross x = %f, y = %f\n", data->h_cross_x, data->h_cross_y);
// 	// fflush(stdout);
// 	data->len_y = SCALE;
// 	if (!wall(map, data->mode, data->h_cross_x, data->h_cross_y))
// 	{
// 		temp = data->h_cross_x;
// 		find_horiz_cross(data);
// 		data->len_x = temp - data->h_cross_x;
// 		if (data->cos_angle < 0.)
// 			data->len_x *= -1;
// 	}
// 	// printf("second_horiz cross x = %f, y = %f\n", data->h_cross_x, data->h_cross_y);
// 	// printf("len horiz = %f\n", data->len_x);
// 	// fflush(stdout);
// 	if (!wall(map, data->mode, data->h_cross_x, data->h_cross_y))
// 	{
// 		find_horiz_cross(data);
// 		// printf("actual cross x = %f, y = %f\n", data->h_cross_x, data->h_cross_y);
// 		// fflush(stdout);
// 	}
// 	// printf("tu4t\n");
// 	// fflush(stdout);
// }

// static void	find_vertic_cross(t_crs *data)
// {
// 	if (fabs(data->len_x) < 1.)
// 			data->v_cross_x += data->len_x * PROD_STEP;
// 	else
// 		data->v_cross_x += data->len_x;
// 	// data->v_cross_x += data->len_x;
// 	data->v_cross_y = data->k * data->v_cross_x + data->b;
// 	// while((int)data->cross_x % SCALE != 0)
// 	while (fabs(fmod(data->v_cross_x, SCALE)) > BAND)
// 	{
// 		data->v_cross_x += data->len_x;
// 		data->v_cross_y = data->k * data->v_cross_x + data->b;
// 	}
// 	// if (data->v_cross_y < 0 || data->v_cross_x < 0)
// 	// {
// 	// 	data->v_cross_x = -1;
// 	// 	data->v_cross_y = -1;
// 	// }
// }

// static void	find_vertic_cross_wall(char **map, t_crs *data, double *x, double *y)
// {
// 	double	temp;

// 	data->v_cross_x = *x;
// 	data->v_cross_y = *y;
// 	if (fabs(data->cos_angle) < 0.0001)
// 		return ;
// 	// *x = data->cross_x;
// 	// *y = data->cross_y;
// 	if (data->cos_angle > 0.)
// 		data->len_x = START_STEP;
// 	else
// 		data->len_x = -START_STEP;
// 	data->len_y = START_STEP;
// 	// printf("VVV actual cross x = %f, y = %f\n", data->v_cross_x, data->v_cross_y);
// 	// fflush(stdout);
// 	find_vertic_cross(data); //replace cross_x cross_y
// 	data->len_y = SCALE;
// 	// printf("VVV actual cross x = %f, y = %f\n", data->v_cross_x, data->v_cross_y);
// 	// fflush(stdout);
// 	if (!wall(map, data->mode, data->v_cross_x, data->v_cross_y))
// 	{
// 		temp = data->v_cross_x;
// 		find_vertic_cross(data);
// 		data->len_x = temp - data->v_cross_x;
// 		if (data->cos_angle < 0.)
// 			data->len_x *= -1;
// 	}
// 	// printf("len vertic = %f\n", data->len_x);
// 	// printf("VVV actual cross x = %f, y = %f\n", data->v_cross_x, data->v_cross_y);
// 	// fflush(stdout);
// 	while (!wall(map, data->mode, data->v_cross_x, data->v_cross_y))
// 	{
// 		find_vertic_cross(data);
// 		// printf("VVV actual cross x = %f, y = %f\n", data->v_cross_x, data->v_cross_y);
// 		// fflush(stdout);
// 	}
// 	// printf("VERTIC ANGLE = %f, actual cross x = %f, y = %f\n", data->angle * 180 / M_PI, data->cross_x, data->cross_y);
// }


void	get_crossing(char **map, t_plr *data)
{
		// printf("START  ANGLE = %f, actual cross x = %f, y = %f\n", angle * 180 / M_PI, *x, *y);
		// fflush(stdout);
	// find_horiz_cross_wall(map, &data, x, y);
		// printf("HORIZ  ANGLE = %f, actual cross x = %f, y = %f\n", angle * 180 / M_PI, data.h_cross_x, data.h_cross_y);
		// fflush(stdout);
	// find_vertic_cross_wall(map, &data, x, y);
		// printf("VERTIC ANGLE = %f, actual cross x = %f, y = %f\n", angle * 180 / M_PI, data.v_cross_x, data.v_cross_y);
		// fflush(stdout);
	// if (data.h_cross_x == -1)
	// {
	// 	*x = data.v_cross_x;
	// 	*y = data.v_cross_y;
	// }
	// else if (data.cos_angle > 0.)
	// 	*x = fmin(data.h_cross_x, data.v_cross_x);
	// else
	// 	*x = fmax(data.h_cross_x, data.v_cross_x);
	// if (data.sin_angle > 0.)
	// 	*y = fmax(data.h_cross_y, data.v_cross_y);
	// else
	// 	*y = fmin(data.h_cross_y, data.v_cross_y);
		// printf("FINISH ANGLE = %f, actual cross x = %f, y = %f\n\n", angle * 180 / M_PI, *x, *y);
	// static int	i = 0;
	// static int	j = 0;
	// j++;
	int	x;
	int	y;

	x = data->cross.x / SCALE;
	y = data->cross.y / SCALE;
	while (map[y][x] == '0' || map[y][x] == '2')
	{
	// 	i++;
		data->cross.x += data->cross.cos_angle / SCALE;
		data->cross.y -= data->cross.sin_angle / SCALE;
		x = data->cross.x / SCALE;
		y = data->cross.y / SCALE;
	}
	// printf("ANGLE = %f, x = %f, y = %f\n\n", data->cross.angle * 180 / M_PI, data->cross.x, data->cross.y);
	// fflush(stdout);
	// printf("line = %d, iter = %d\n", j, i); //old 1 image: j = 1600, i = 860253
}
