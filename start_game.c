/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:07:58 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/13 19:59:46 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		start_win(t_win *win)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		return (-1);
	mlx_get_screen_size(win->mlx, &(win->x_win), &(win->y_win));
	win->img = mlx_new_image(win->mlx, win->x_win, win->y_win);
	if (!win->img)
		return (-1);
	win->addr = mlx_get_data_addr(win->img, &(win->bpp), \
								&(win->line_len), &(win->en));
	if (!win->addr)
		return (-1);
	win->win = mlx_new_window(win->mlx, win->x_win, win->y_win, "cub3d");
	if (!win->win)
		return (-1);
	// if (get_texture(win, cnfg) < 0) uncomment when the textures are ready
	// 	return (-1);
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
	while (map[y] && y_img <= cnfg->y_res)
	{
		x = 0;
		x_img = 0;
		while (map[y][x] && x_img <= cnfg->x_res)
		{
			if (map[y][x] == '1')
				my_pixel_put(win, x_img, y_img, 0x001100FF);
			else
				my_pixel_put(win, x_img, y_img, 0x000000);
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

void put_raycast(t_win * win, double dist, int win_x, int color)
{
	if (win_x < win->x_win)
	{
		double wall_height = win->y_win * 16 / dist;
		put_ray(win, color, round(wall_height), win_x);
	}
}

int		get_wall_side(float y, float x, float ray_dir, char **map)
{
	if (map[(int)(y / SCALE)][(int)((x - cos(ray_dir) * 0.1) / SCALE)] == '0')
	{
		if (cos(ray_dir) > 0)
			return COLOR_EA;
		return COLOR_WE;
	}
	if (sin(ray_dir) > 0)
		return COLOR_NO;
	return COLOR_SO;
}

int		put_player(t_win *win, t_plr *plr_data, char **map)
{
	double	y;
	double	x;
	double	dir_start;
	double	dir_end;
	double dist;
	
	dir_start = plr_data->plr_dir_rad + M_PI_2 / 3;
	dir_end = plr_data->plr_dir_rad - M_PI_2 / 3;
	int i = 0;
	while (dir_start >= dir_end)
	{
		y = plr_data->plr_pos_y;
		x = plr_data->plr_pos_x;
		while (map[(int)(y / SCALE)][(int)(x / SCALE)] == '0' || map[(int)(y / SCALE)][(int)(x / SCALE)] == '2')
		{
			y -= sin(dir_start) / SCALE;
			x += cos(dir_start) / SCALE;
		}
		dist = sqrtf((y - plr_data->plr_pos_y) * (y - plr_data->plr_pos_y) + (x - plr_data->plr_pos_x) * (x - plr_data->plr_pos_x)) * sinf(M_PI / 2 - dir_start + plr_data->plr_dir_rad);
		put_raycast(win, dist, i, get_wall_side(y, x, dir_start, map));
		i += 1;
		dir_start -= M_PI / 3 / win->x_win;
	}
	return (0);
}

void	put_screen(t_data *all)
{
	mlx_do_sync(all->win->mlx);
	put_map(all->win, all->cnfg, all->map);
	put_player(all->win, all->plr_data, all->map);
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
	if (start_win(all->win) < 0)
		return (-1); //error management
	put_map(all->win, all->cnfg, all->map);
	put_player(all->win, all->plr_data, all->map);
	// raycast(all->map, all->plr_data, all->win);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	mlx_hook(all->win->win, 2, (1L<<0), &key_handle, all);
	mlx_hook(all->win->win, 17, (1L<<17), stop_game, all);
	mlx_loop(all->win->mlx);
	return (0);
}