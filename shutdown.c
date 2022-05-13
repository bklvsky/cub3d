/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shutdown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 02:12:40 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/13 23:49:23 by dselmy           ###   ########.fr       */
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
	shut_down(all, 0);
	return (0);
}

void	manage_arg_errors(int error)
{
	ft_putstr_fd("Programm arguments error: ", 2);
	if (error == ERR_ARG_NO_FILE)
		ft_putstr_fd("no scene desription file supplied.\n", 2);
	else if (error == ERR_TOO_MANY_ARG)
		ft_putstr_fd("too many arguments.\n", 2);
	else if (error == ERR_ARG_FORMAT)
		ft_putstr_fd("wrong scene description file format.\n", 2);
	else if (error == ERR_ARG_UNKNOWN)
		ft_putstr_fd("unknown argument.\n", 2);
}

void	manage_config_errors(int error)
{
	ft_putstr_fd("Scene configuration error: ", 2);
	if (error == ERR_MISSING_CONF_DATA)
		ft_putstr_fd("incomplete scene configuration data.\n", 2);
	else if (error == ERR_RESOLUTION)
		ft_putstr_fd("wrong resolution data formatting.\n", 2);
	else if (error == ERR_TEX_FORMAT)
		ft_putstr_fd("wrong texture file format.\n", 2);
	else if (error == ERR_COLOR)
		ft_putstr_fd("wrong color configuration data.\n", 2);
	else if (error == ERR_NO_MAP)
		ft_putstr_fd("no map encountered.\n", 2);
	else if (error == ERR_SYM_AFTER_MAP)
		ft_putstr_fd("symbols after the map.\n", 2);
	else if (error == ERR_UKNOWN_SYM)
		ft_putstr_fd("configuration identifiers error.\n", 2);
	else if (error == ERR_NOT_CLOSED_MAP)
		ft_putstr_fd("the map is not closed.\n", 2);
	else if (error == ERR_DUPL_DATA)
		ft_putstr_fd("configuration data duplicated.\n", 2);
	else if (error == ERR_NO_PLR)
		ft_putstr_fd("player not found.\n", 2);
	else if (error == ERR_MULT_PLRS)
		ft_putstr_fd("multiple players encountered.\n", 2);
}

void	shut_down(t_data *all, int error)
{
	if (all)
		free_all(all);
	if (error == ERR_STD)
		perror("Error\n");
	else if (error < 0)
	{
		ft_putstr_fd("Error\n", 2);
		if (error >= ERR_ARG_UNKNOWN)
			manage_arg_errors(error);
		else
			manage_config_errors(error);
	}
	exit(0);
}
