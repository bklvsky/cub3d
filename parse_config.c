/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:25:55 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/11 23:45:27 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_all_data(t_data *all) //dont need it anymore
{
	int		i;

	i = -1;
	while (++i < SIZE_DATA)
	{
		if (all->cnfg->data[i] == 0)
			shut_down(all, ERR_MISSING_CONF_DATA);
	}
}

char	*get_identifier(int id_number)
{
	if (id_number == NO_TEX)
		return "NO ";
	else if (id_number == SO_TEX)
		return "SO ";
	else if (id_number == WE_TEX)
		return "WE ";
	else if (id_number == EA_TEX)
		return "EA ";
	else if (id_number == FLOOR_COL)
		return "F ";
	else if (id_number == CEIL_COL)
		return "C ";
	return "";
}

int		id_is_valid(char *current_id, char *line)
{
	if (ft_strncmp(line, current_id, ft_strlen(current_id)) != 0)
		return (0);
	return (1);
}

int		check_identifiers(int id_number, t_config *cnfg, char *line)
{
	if (id_number == MAP)
		return (1);
	if (!id_is_valid(get_identifier(id_number), line))
		return (ERR_UKNOWN_SYM); // err not valid identifier or identifiers is wrong order
	if (id_number == NO_TEX)
		return (parse_tex_pth(&cnfg->tex_paths[NO_TEX], line, &cnfg->data[NO_TEX]));
	else if (id_number == SO_TEX)
		return (parse_tex_pth(&cnfg->tex_paths[SO_TEX], line, &cnfg->data[SO_TEX]));
	else if (id_number == WE_TEX)
		return (parse_tex_pth(&cnfg->tex_paths[WE_TEX], line, &cnfg->data[WE_TEX]));
	else if (id_number == EA_TEX)
		return (parse_tex_pth(&cnfg->tex_paths[EA_TEX], line, &cnfg->data[EA_TEX]));
	else if (id_number == FLOOR_COL)
		return (parse_color(cnfg->floor_color, line, &cnfg->data[FLOOR_COL]));
	else if (id_number == CEIL_COL)
		return (parse_color(cnfg->ceil_color, line, &cnfg->data[CEIL_COL]));
	else
		return (1);
}

int		parse_color(int	*color, char *line, int *flag)
{
	char	**array;
	int		rgb_arr[3];
	char	*line_wo_spaces;
	int		y;

	if (!set_flag(flag)) // dont need it anymore
		return (ERR_DUPL_DATA);
	if (!(line_wo_spaces = ft_strtrim(line + 1, " ")))
		return (ERR_STD);
	else if (!(array = ft_split(line_wo_spaces, ',')))
		return (parse_color_end(NULL, line_wo_spaces, ERR_STD));;
	y = 0;
	while (array[y])
	{
		if (!only_num(array[y]) || y > 2)
			return (parse_color_end(array, line_wo_spaces, ERR_COLOR));
		rgb_arr[y] = ft_atoi(array[y]);
		if (rgb_arr[y] < 0 || rgb_arr[y] > 255)
			return (parse_color_end(array, line_wo_spaces, ERR_COLOR));
		y += 1;
	}
	if (y != 3)
		return (parse_color_end(array, line_wo_spaces, ERR_COLOR));
	*color = create_trgb(0, rgb_arr[0], rgb_arr[1], rgb_arr[2]);
	return (parse_color_end(array, line_wo_spaces, 0));
}

int		parse_tex_pth(char **tex_path, char *line, int *flag)
{
	if (!set_flag(flag)) // dont need it anymore
		return (ERR_DUPL_DATA);
	if (!(*tex_path = ft_strtrim(line + 2, " ")))
		return (ERR_STD);
	if (!check_file_format(*tex_path, ".bmp") && !check_file_format(*tex_path, ".xpm")) // not bmp
		return (ERR_TEX_FORMAT);
	return (0);
}

