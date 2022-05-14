/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:28:38 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/15 02:02:35 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_color_end(char **array, char *line_wo_spaces, int error)
{
	if (error == ERR_STD)
		put_error(MEM_ERR, ERR_STD);
	else if (error)
		put_error(CONFIG_ERR, error);
	if (array)
		free_arr(array);
	free(line_wo_spaces);
	return (error);
}
