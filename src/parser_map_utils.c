/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 00:14:21 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/13 05:07:30 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map_h(t_list *lst)
{
	int		map_h;
	t_list	*tmp;

	map_h = 0;
	tmp = lst;
	while (tmp && ((char *)tmp->content)[0] != 0)
	{
		map_h += 1;
		tmp = tmp->next;
	}
	return (map_h);
}

void	get_x_max(int *x_max, int x)
{
	if (x > *x_max)
		*x_max = x;
}

void	skip_spaces_line(char *line, int *x, int *flag)
{
	while (line[*x] == ' ')
		*x += 1;
	*flag = 1;
}

void	skip_spaces_col(char **map, int *y, int x)
{
	while (map[*y] && (map[*y][x] == ' ' || map[*y][x] == '\0'))
		*y += 1;
}

void	skip_map_sym_col(char **map, int *y, int x)
{
	while (map[*y] && map[*y][x] && map[*y][x] != ' ')
		*y += 1;
}
