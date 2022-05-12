/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:28:38 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/11 23:32:54 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_color_end(char **array, char *line_wo_spaces, int error)
{
	if (array)
		free_arr(array);
	if (line_wo_spaces)
		free(line_wo_spaces);
	return (error);
}
