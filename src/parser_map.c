/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 23:06:16 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/15 01:52:35 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_ver(char **map, int x_max)
{
	int		x;
	int		y;
	int		flag_whitespace;

	x = -1;
	while (++x <= x_max)
	{
		flag_whitespace = 0;
		y = 0;
		while (map[y])
		{
			if (flag_whitespace == 1)
				if (map[y - 1][x] != '1')
					return (put_error(CONFIG_ERR, ERR_NOT_CLOSED_MAP));
			skip_spaces_col(map, &y, x);
			if (map[y] && (map[y][x] != '1'))
				return (put_error(CONFIG_ERR, ERR_NOT_CLOSED_MAP));
			flag_whitespace = 1;
			skip_map_sym_col(map, &y, x);
		}
		if (map[y - 1][x] != '1' && map[y - 1][x] != ' ' && map[y - 1][x])
			return (put_error(CONFIG_ERR, ERR_NOT_CLOSED_MAP));
	}
	return (0);
}

int	make_rect_map(char **map, int x_max)
{
	char	*new_line;
	int		y;

	y = 0;
	while (map[y])
	{
		new_line = (char *)ft_calloc(x_max + 1, sizeof(char));
		if (!new_line)
			return (put_error(MEM_ERR, ERR_STD));
		ft_strlcpy(new_line, map[y], x_max + 1);
		free(map[y]);
		map[y] = new_line;
		y += 1;
	}
	return (0);
}

int	check_one_line(char *line, t_plr *plr_data)
{
	int		x;
	int		flag_whitespace;

	x = 0;
	flag_whitespace = 0;
	while (line[x])
	{
		if (flag_whitespace == 1)
			if (line[x - 1] != '1')
				return (put_error(CONFIG_ERR, ERR_NOT_CLOSED_MAP));
		skip_spaces_line(line, &x, &flag_whitespace);
		if (line[x] != '1' && line[x] != '\0')
			return (put_error(CONFIG_ERR, ERR_NOT_CLOSED_MAP));
		if (check_sym_map(line, &x, plr_data) != 0)
			return (put_error(CONFIG_ERR, ERR_UNKNOWN_SYM_MAP));
	}
	if (line[x - 1] != '1' && line[x - 1] != ' ')
		return (put_error(CONFIG_ERR, ERR_NOT_CLOSED_MAP));
	return (x);
}

int	check_sym_map(char *line, int *x, t_plr *plr_data)
{	
	while (ft_strchr("01NSWE", line[*x]) && line[*x])
	{
		if (ft_strchr("NSWE", line[*x]))
		{
			plr_data->plr_num += 1;
			plr_data->plr_pos_x = *x * SCALE;
			plr_data->plr_pos_y = GET_PLR_Y;
			get_plr_dir(line[*x], plr_data);
			line[*x] = '0';
		}
		*x += 1;
	}
	if (line[*x] != ' ' && line[*x] != '\0')
		return (-1);
	return (0);
}

int	check_map_hor(char **map, t_plr *plr_data, int *x_max)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = check_one_line(map[y], plr_data);
		if (x < 0)
			return (x);
		else
			get_x_max(x_max, x);
		if (plr_data->plr_num > 1)
			return (put_error(CONFIG_ERR, ERR_MULT_PLRS));
		if (plr_data->plr_pos_y == GET_PLR_Y)
			plr_data->plr_pos_y = y * SCALE;
		y += 1;
	}
	if (plr_data->plr_num == 0)
		return (put_error(CONFIG_ERR, ERR_NO_PLR));
	return (0);
}
