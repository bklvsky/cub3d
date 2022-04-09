/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 23:06:16 by dselmy            #+#    #+#             */
/*   Updated: 2021/08/08 03:35:53 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		check_map_ver(char **map, int x_max)
{
	int		x;
	int		y;
	int		flag_whitespace;
	
	x = -1;
//	printf("checking map vertically\n");
	while (++x <= x_max)
	{
		flag_whitespace = 0;
		y = 0;
		while (map[y])
		{
			if (flag_whitespace == 1)
				if (map[y-1][x] != '1')
					return (ERR_NOT_CLOSED_MAP);
			skip_spaces_col(map, &y, x);
			if (map[y] && (map[y][x] != '1'))
			{
//				printf("map not closed on the upper side\n");
				return (ERR_NOT_CLOSED_MAP);
			}
			flag_whitespace = 1;
			skip_map_sym_col(map, &y, x);
		}
		if (map[y-1][x] != '1' && map[y-1][x] != ' ' && map[y-1][x])
		{
//			printf("the map is not closed on the last line\n");
			return (ERR_NOT_CLOSED_MAP);
		}
	}
//	printf("map checked vertically, all good\n");
	return (0);
}

int		make_rect_map(char **map, int x_max)
{
	char	*new_line;
	int		y;

	y = 0;
	while (map[y])
	{
		new_line = (char *)ft_calloc(x_max + 1, sizeof(char));
		if (!new_line)
			return (ERR_STD);
		ft_strlcpy(new_line, map[y], x_max + 1);
		free(map[y]);
		map[y] = new_line;
		y += 1;
	}
	return (0);
}

int		check_one_line(char *line, t_plr *plr_data)
{
	int		x;
	int		flag_whitespace;
	
	x = 0;
	flag_whitespace = 0;
//	printf("in checkoneline\n");
	while (line[x])
	{
//		printf("checking line %s\n", line);
		if (flag_whitespace == 1)
			if (line[x-1] != '1')
				return (ERR_NOT_CLOSED_MAP);
		skip_spaces_line(line, &x, &flag_whitespace);
//		printf("skipped spaces, x = %d, line[x] = %c\n", x, line[x]);
		if (line[x] != '1' && line[x] != '\0')
			return (ERR_NOT_CLOSED_MAP);
//		printf("checked for left side closed\n");
		if (check_sym_map(line, &x, plr_data) != 0)
			return (ERR_UKNOWN_SYM);
//		printf("x after check sym = %d lin[x] = %c\n", x, line[x]);
	}
//	printf("we went out pf the cycle\n, line [x-1] = %c\n", line[x-1]);
	if (line[x-1] != '1' && line[x-1] != ' ')
		return (ERR_NOT_CLOSED_MAP);
	return (x);
}

int		check_sym_map(char *line, int *x, t_plr *plr_data)
{	
	while (ft_strchr("012NSWE", line[*x]) && line[*x])
	{
		if (ft_strchr("NSWE", line[*x]))
		{
			line[*x] = '0';
			plr_data->plr_num += 1;
			plr_data->plr_pos_x = *x * SCALE;
			plr_data->plr_pos_y = GET_PLR_Y;
			plr_data->plr_dir_rad = M_PI_2;
		}
		*x += 1;
	}
	if (line[*x] != ' ' && line[*x] != '\0')
		return (ERR_UKNOWN_SYM);
	return (0);
}

int		check_map_hor(char **map, t_plr *plr_data, int *x_max)

{
	int		x;
	int		y;

	y = 0;
//	printf("checking map horizontally\n");
	while (map[y])
	{
//		printf("y = %d, map[y] = %s\n", y, map[y]);
//		printf("y = %d\n", y);
		x = check_one_line(map[y], plr_data);
		if (x < 0)
			return (x);
		else
			get_x_max(x_max, x);
		if (plr_data->plr_num > 1)
			return (ERR_MULT_PLRS);
		if (plr_data->plr_pos_y == GET_PLR_Y)
			plr_data->plr_pos_y = y * SCALE;
		y += 1;
	}
	if (plr_data->plr_num == 0)
		return (ERR_NO_PLR);
//	printf("map checked horizontally, all good\n");
	return (0);
}
