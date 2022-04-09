/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:07:58 by dselmy            #+#    #+#             */
/*   Updated: 2021/10/26 01:08:07 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		start_win(t_win *win, int x_res, int y_res)
{
	printf("starting a window\n");
	win->mlx = mlx_init();
	printf("got mlx_ptr\n");
	win->img = mlx_new_image(win->mlx, x_res, y_res);
	printf("got img_ptr\n");
	win->addr = mlx_get_data_addr(win->img, &(win->bpp), &(win->line_len), &(win->en));
	printf("got addr_ptr\n");
	win->win = mlx_new_window(win->mlx, x_res, y_res, "cub3d");
	printf("got new window\n");
	win->x_win = x_res;
	win->y_win = y_res;
	return (0);
}

int		put_map(t_win *win, t_config *cnfg, char **map)
{
	int		x;
	int		y;
	int		x_img;
	int		y_img;
	
	y_img = 0;
	y = 0;
//	printf("in put map\n");
	while (map[y] && y_img <= cnfg->y_res)
	{
		x = 0;
		x_img = 0;
		while (map[y][x] && x_img <= cnfg->x_res)
		{
			if (map[y][x] == '1')
			{
		//		printf("in pixel put in put map\n");
				my_pixel_put(win, x_img, y_img, 0x001100FF);
			}
			x_img += 1;
			if ((x_img % SCALE) == 0)
				x += 1;
		}
		y_img += 1;
		if ((y_img % SCALE) == 0)
			y += 1;
	}
	return (0);
}

void	print_arr(char **arr)
{
	int		y;

	y = 0;
	while (arr[y])
	{
		printf("%d %s\n", y, arr[y]);
		y += 1;
	}
}

void	print_config(t_config *cnfg, char **map)
{
	print_arr(map);
	printf("x_res = %d\n", cnfg->x_res);
	printf("y_res = %d\n", cnfg->y_res);
	printf("no_tex_path = %s\n", cnfg->no_tex_path);
	printf("so_tex_path = %s\n", cnfg->so_tex_path);
	printf("ea_tex_path = %s\n", cnfg->ea_tex_path);
	printf("we_tex_path = %s\n", cnfg->we_tex_path);
	printf("spr_tex_path = %s\n", cnfg->spr_tex_path);
}

void	put_square(t_win *win, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < SCALE)
	{
		j = 0;
		while(j < SCALE)
		{
			my_pixel_put(win, x + j, y + i, 0x00FF0000);
			j += 1;
		}
		i += 1;
	}
}

int		put_player(t_win *win, t_plr *plr_data, char **map)
{
	double	y;
	double	x;
	double	dir_start;
	double	dir_end;
	
	dir_start = plr_data->plr_dir_rad - M_PI_4;
	dir_end = plr_data->plr_dir_rad + M_PI_4;
	while (dir_start <= dir_end)
	{
		y = plr_data->plr_pos_y;
		x = plr_data->plr_pos_x;
		while (map[(int)(y / SCALE)][(int)(x / SCALE)] == '0' || map[(int)(y / SCALE)][(int)(x / SCALE)] == '2')
		{
			my_pixel_put(win, (int)x, (int)y, 0x00FFA500);
			y -= sin(dir_start);
			x += cos(dir_start);
		}
		dir_start += M_PI_2 / 512;
	}
//	printf("in put player\n");
	//put_square(win, (int)plr_data->plr_pos_x, (int)plr_data->plr_pos_y);
	return (0);
}

int		plr_up(char **map, t_plr *plr_data)
{
	double	y;
	double	x;

	y = plr_data->plr_pos_y - sin(plr_data->plr_dir_rad);
	x = plr_data->plr_pos_x + cos(plr_data->plr_dir_rad);
//	printf("in plr up\n");
	if (map[(int)(y / SCALE)][(int)(x / SCALE)] != '1')
	{
		plr_data->plr_pos_y = y;
		plr_data->plr_pos_x = x;
	}
	return (0);
}

int		plr_down(char **map, t_plr *plr_data)
{
//	printf("in plr down\n");
	double	y;
	double	x;

	y = plr_data->plr_pos_y + sin(plr_data->plr_dir_rad);
	x = plr_data->plr_pos_x - cos(plr_data->plr_dir_rad);
	if (map[(int)(y / SCALE)][(int)(x / SCALE)] != '1')
	{
		plr_data->plr_pos_y = y;
		plr_data->plr_pos_x = x;
	}
	return (0);
}

int		plr_left(char **map, t_plr *plr_data)
{
	double	y;
	double	x;

	y = plr_data->plr_pos_y - cos(plr_data->plr_dir_rad);
	x = plr_data->plr_pos_x - sin(plr_data->plr_dir_rad);
//	printf("pos y = %d, pos x = %d\n", plr_data->plr_pos_y, plr_data->plr_pos_x);
	if (map[(int)(y / SCALE)][(int)(x / SCALE)] != '1')
	{
		plr_data->plr_pos_y = y;
		plr_data->plr_pos_x = x;
	}
//	printf(" new pos y = %d, pos x = %d\n", plr_data->plr_pos_y, plr_data->plr_pos_x);
	return (0);
}

int		plr_right(char **map, t_plr *plr_data)
{
	double	y;
	double	x;

	y = plr_data->plr_pos_y + cos(plr_data->plr_dir_rad);
	x = plr_data->plr_pos_x + sin(plr_data->plr_dir_rad);
	if (map[(int)(y / SCALE)][(int)(x / SCALE)] !='1')
	{
		plr_data->plr_pos_y = y;
		plr_data->plr_pos_x = x;
	}
	return (0);
}



int		plr_rot_right(t_plr *plr_data)
{
	plr_data->plr_dir_rad -= 0.05;
	return (0);
}

int		plr_rot_left(t_plr *plr_data)
{
	plr_data->plr_dir_rad += 0.05;
	return (0);
}

void	put_screen(t_data *all)
{
//	printf("in put screen\n");
	mlx_do_sync(all->win->mlx);
//	mlx_destroy_image(all->win->mlx, all->win->img);
//	all->win->img = mlx_new_image(all->win->mlx, all->cnfg->x_res, all->cnfg->y_res);
//	all->win->addr = mlx_get_data_addr(all->win->img, &(all->win->bpp), &(all->win->line_len), &(all->win->en));
	raycast(all->map, all->plr_data, all->win);
//	put_map(all->win, all->cnfg, all->map);
//	put_player(all->win, all->plr_data, all->map);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
}

int		key_handle(int key, t_data *all)
{
	if (key == 119 || key == 65362)
		plr_up(all->map, all->plr_data);
	if (key == 115 || key == 65364)
		plr_down(all->map, all->plr_data);
	if (key == 97)
		plr_left(all->map, all->plr_data);
	if (key == 100)
		plr_right(all->map, all->plr_data);
	if (key == 65361)
		plr_rot_left(all->plr_data);
	if (key == 65363)
		plr_rot_right(all->plr_data);
	put_screen(all);
	return(0);
}

int		cub(t_data *all)
{
//	print_config(all->cnfg, all->map);
	start_win(all->win, all->cnfg->x_res, all->cnfg->y_res);
//	put_map(all->win, all->cnfg, all->map);
//	put_player(all->win, all->plr_data, all->map);
	raycast(all->map, all->plr_data, all->win);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	mlx_hook(all->win->win, 2, (1L<<0), &key_handle, all);
	mlx_hook(all->win->win, 17, (1L<<17), stop_game, all);
	mlx_loop(all->win->mlx);
	return (0);
}