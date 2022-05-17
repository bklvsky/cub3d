/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:25:55 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/17 22:45:01 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_identifier(int id_number)
{
	if (id_number == NO_TEX)
		return ("NO ");
	else if (id_number == SO_TEX)
		return ("SO ");
	else if (id_number == WE_TEX)
		return ("WE ");
	else if (id_number == EA_TEX)
		return ("EA ");
	else if (id_number == FLOOR_COL)
		return ("F ");
	else if (id_number == CEIL_COL)
		return ("C ");
	return ("");
}

int	id_is_valid(char *line)
{
	return (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) \
	|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3) \
	|| !ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2));
}

int	check_id(t_config *cnfg, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (parse_tex_pth(cnfg, NO_TEX, line));
	else if (!ft_strncmp(line, "SO ", 3))
		return (parse_tex_pth(cnfg, SO_TEX, line));
	else if (!ft_strncmp(line, "WE ", 3))
		return (parse_tex_pth(cnfg, WE_TEX, line));
	else if (!ft_strncmp(line, "EA ", 3))
		return (parse_tex_pth(cnfg, EA_TEX, line));
	else if (!ft_strncmp(line, "F ", 2))
	{
		if (set_flag(cnfg->data + FLOOR_COL) < 0)
			return (put_error(CONFIG_ERR, ERR_DUPL_DATA));
		return (parse_color(cnfg->floor_color, line));
	}
	else if (!ft_strncmp(line, "C ", 2))
	{
		if (set_flag(cnfg->data + CEIL_COL) < 0)
			return (put_error(CONFIG_ERR, ERR_DUPL_DATA));
		return (parse_color(cnfg->ceil_color, line));
	}
	return (1);
}

int	parse_color(int	*color, char *line)
{
	char	**array;
	int		rgb_arr[3];
	char	*line_wo_spaces;
	int		y;

	line_wo_spaces = ft_strtrim(line + 1, " ");
	if (!line_wo_spaces)
		return (put_error(MEM_ERR, ERR_STD));
	array = ft_split(line_wo_spaces, ',');
	if (!array)
		return (parse_color_end(array, line_wo_spaces, ERR_STD));
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

int	parse_tex_pth(t_config *cnfg, int tex_id, char *line)
{
	if (set_flag(cnfg->data + tex_id) < 0)
		return (put_error(CONFIG_ERR, ERR_DUPL_DATA));
	cnfg->tex_paths[tex_id] = ft_strtrim(line + 2, " ");
	if (!(cnfg->tex_paths[tex_id]))
		return (put_error(MEM_ERR, ERR_STD));
	if (!check_file_format(cnfg->tex_paths[tex_id], ".xpm"))
		return (put_error(cnfg->tex_paths[tex_id], ERR_TEX_FORMAT));
	return (0);
}
