/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:25:55 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/12 21:28:34 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_all_data(t_data *all)
{
	int		i;

	i = -1;
	/*printf("in check all data now\n");*/
	while (++i <= 8)
	{
	//	printf("i = %d data[i] = %d\n", i, all->cnfg->data[i]);
		if (all->cnfg->data[i] == 0)
			shut_down(all, ERR_MISSING_CONF_DATA);
	}
}

int		check_identifiers(t_config *cnfg, char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0) // not needed anymore
		return (parse_resolution(line, cnfg, &cnfg->data[RES]));
	else if (ft_strncmp(line, "NO ", 3) == 0)
		return (parse_tex_pth(&cnfg->no_tex_path, line, &cnfg->data[NO_TEX]));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (parse_tex_pth(&cnfg->so_tex_path, line, &cnfg->data[SO_TEX]));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (parse_tex_pth(&cnfg->we_tex_path, line, &cnfg->data[WE_TEX]));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (parse_tex_pth(&cnfg->ea_tex_path, line, &cnfg->data[EA_TEX]));
	else if (ft_strncmp(line, "S ", 2) == 0) // not needed anymore
		return (parse_tex_pth(&cnfg->spr_tex_path, line, &cnfg->data[SP_TEX]));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (parse_color(&cnfg->floor_color, line, &cnfg->data[FLOOR_COL]));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (parse_color(&cnfg->ceil_color, line, &cnfg->data[CEIL_COL]));
	else
		return (1);
}

int		parse_color(int	*color, char *line, int *flag)
{
	char	**array;
	int		rgb_arr[3];
	char	*line_wo_spaces;
	int		y;
	
	if (!set_flag(flag))
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
	// it should store textures like mlx images; copy from solong
	if (!set_flag(flag))
		return (ERR_DUPL_DATA);
	if (!(*tex_path = ft_strtrim(line + 2, " ")))
		return (ERR_STD);
	if (!check_file_format(*tex_path, ".bmp")) // not bmp
		return (ERR_TEX_FORMAT);
	return (0);
}

// not needed anymore; make it get resolution from screen size
int		parse_resolution(char *line, t_config *cnfg, int *flag)
{
	char	**array;
	int		y;
	int		num;

	if (!set_flag(flag))
		return (ERR_DUPL_DATA);
	if (!(array = ft_split(line + 1, ' ')))
		return (ERR_STD);  //protect malloc
	y = 0;
	while (array[y])
	{
		if (!only_num(array[y]) || y > 1)
			return(parse_res_end(array, ERR_RESOLUTION));
		else
			num = ft_atoi(array[y]);
		if (num > 0 && num <= 3000)   //get screen size later
		{
			if (y == 0)
				cnfg->x_res = num;
			else if (y == 1)
				cnfg->y_res = num;
		}
		y += 1;          
	}
	free_arr(array);
	return (0);
}