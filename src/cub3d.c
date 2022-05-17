/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 00:14:57 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/17 12:09:04 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_arg(int argc, char **argv, t_data *all)
{
	if (argc > 2)
		return (put_error(NULL, ERR_TOO_MANY_ARG));
	else
	{
		if (!check_file_format(argv[1], ".cub"))
			return (put_error(argv[1], ERR_ARG_FORMAT));
		all->fd = open(argv[1], O_RDONLY);
		if (all->fd < 0)
			return (put_error(argv[1], ERR_STD));
		if (read(all->fd, NULL, 0) < 0)
			return (put_error(argv[1], ERR_STD));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*all;

	if (argc < 2)
	{
		put_error(NULL, ERR_ARG_NO_FILE);
		return (0);
	}
	all = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!all)
		return (put_error(MEM_ERR, ERR_STD));
	if (init_struct(all, argv[1]) < 0)
	{
		put_error(MEM_ERR, ERR_STD);
		shut_down(all);
	}
	if (check_arg(argc, argv, all) < 0)
		shut_down(all);
	parser(all);
	cub(all);
	return (0);
}
