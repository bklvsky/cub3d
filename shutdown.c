/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 02:12:40 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/13 20:21:18 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		stop_game(t_data *all)
{
//	mlx_destroy_image(all->win->mlx, all->win->img);
//	mlx_destroy_window(all->win->mlx, all->win->win);
	mlx_destroy_image(all->win->mlx, all->win->img);
	mlx_destroy_window(all->win->mlx, all->win->win);
	shut_down(all, 0);
	return (0);
}

void	free_win(t_data *all)
{
/*	if (all->win->mlx)
	{
		free(all->win->mlx);
		free(all->win->win);
		free(all->win->img);
		free(all->win->addr);
	}*/
	free(all->win);
	all->win = NULL;
}

void	free_config(t_data *all)
{
	free(all->cnfg->ea_tex_path);
	free(all->cnfg->we_tex_path);
	free(all->cnfg->no_tex_path);
	free(all->cnfg->so_tex_path);
	free(all->cnfg);
	all->cnfg = NULL;
}

void	manage_arg_errors(int error)
{
	write(2, "Programm arguments error: ", 26);
	if (error == ERR_ARG_NO_FILE)
		write(2, "no scene desription file supplied.\n", 35);
	else if (error == ERR_TOO_MANY_ARG)
		write(2, "too many arguments.\n", 20);
	else if (error == ERR_ARG_FORMAT)
		write(2, "wrong scene description file format.\n", 37);
	else if (error == ERR_ARG_UNKNOWN)
		write(2, "unknown argument.\n", 18);
}

void	manage_config_errors(int error)
{
	write(2, "Scene configuration error: ", 27);
	if (error == ERR_MISSING_CONF_DATA)
		write(2, "incomplete scene configuration data.\n", 37);
	else if (error == ERR_RESOLUTION)
		write(2, "wrong resolution data formatting.\n", 34);
	else if (error == ERR_TEX_FORMAT)
		write(2, "wrong texture file format.\n", 27);
	else if (error == ERR_COLOR)
		write(2, "wrong color configuration data.\n", 32);
	else if (error == ERR_NO_MAP)
		write(2, "no map encountered.\n", 20);
	else if (error == ERR_SYM_AFTER_MAP)
		write(2, "symbols after the map.\n", 23);
	else if (error == ERR_UKNOWN_SYM)
		write(2, "uknown symbols encountered.\n", 28);
	else if (error == ERR_NOT_CLOSED_MAP)
		write(2, "the map is not closed.\n", 23);
	else if (error == ERR_DUPL_DATA)
		write(2, "configuration data duplicated.\n", 31);
	else if (error == ERR_NO_PLR)
		write(2, "player not found.\n", 18);
	else if (error == ERR_MULT_PLRS)
		write(2, "multiple players encountered.\n", 30);
}

void	free_all(t_data *all)
{
	free_config(all);
	free_arr(all->map);
	free(all->plr_data);
	free_win(all);
	free(all);
}

void	shut_down(t_data *all, int error)
{
	if (all)
		free_all(all);
	if (error == ERR_STD)
		perror("Error\n");
	else if (error < 0)
	{
		write(2, "Error\n", 6);
		if (error >= ERR_ARG_UNKNOWN)
			manage_arg_errors(error);
		else
			manage_config_errors(error);
	}
	exit(0);
}
