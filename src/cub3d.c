/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 00:14:57 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/13 20:14:55 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_arg(int argc, char **argv, t_data *all)
{
	if (argc < 2)
		shut_down(all, ERR_ARG_NO_FILE);
	else if (argc > 2)
		shut_down(all, ERR_TOO_MANY_ARG);
	else
	{
		if (!check_file_format(argv[1], ".cub"))
			shut_down(all, ERR_ARG_FORMAT);
		all->fd = open(argv[1], O_RDONLY);
		if (all->fd < 0)
			shut_down(all, ERR_STD);
	}
}

int	main(int argc, char **argv)
{
	t_data	*all;

	all = (t_data *)malloc(sizeof(t_data));
	if (!all)
		shut_down(all, ERR_STD);
	if (init_struct(all) != 0)
		shut_down(all, ERR_STD);
	check_arg(argc, argv, all);
	parser(all);
	cub(all);
	return (0);
}
