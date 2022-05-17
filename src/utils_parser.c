/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:45:28 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/17 22:46:41 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_flag(int *flag)
{
	if (!*flag)
		*flag = 1;
	else
		return (-1);
	return (0);
}

int	check_all_data(int *data)
{
	int	i;

	i = 0;
	while (i <= MAP)
	{
		if (!data[i])
			return (put_error(CONFIG_ERR, ERR_MISSING_CONF_DATA));
		i += 1;
	}
	return (0);
}
