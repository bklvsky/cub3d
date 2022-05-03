/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 00:14:57 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/19 20:27:19 by dselmy           ###   ########.fr       */
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
		else if ((all->fd = open(argv[1], O_RDONLY)) < 0)
			shut_down(all, ERR_STD);

	}
}

int     main(int argc, char **argv)
{
	t_data	*all;
	int		error;

	error = 0;
	if (!(all = (t_data *)malloc(sizeof(t_data))))
		shut_down(all, ERR_STD);
	if ((error = init_struct(all)) != 0)
		shut_down(all, error);
	check_arg(argc, argv, all);
	parser(all);
	// printf("%d %d\n", all->map_h, all->map_width);
	cub(all);
//	shut_down(all, 0);
		/*3. parse map -> errorccodeall  in case of unfamiliar characters 
										not closed map
		4. check if any essential data is missing -> errorcall
		5. cub3d*/
	return (0);
}