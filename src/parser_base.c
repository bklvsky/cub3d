/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:25:18 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/17 00:30:44 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	make_map_arr(t_data *all, t_list **map_ptr, int map_h)
{
	int		i;

	i = -1;
	all->map = (char **)ft_calloc(map_h + 1, sizeof(char *));
	if (!all->map)
		return (put_error(MEM_ERR, ERR_STD));
	while (*map_ptr && ++i < map_h)
	{
		all->map[i] = ft_strdup((char *)(*map_ptr)->content);
		if (!all->map[i])
			return (put_error(MEM_ERR, ERR_STD));
		*map_ptr = (*map_ptr)->next;
	}
	all->map[map_h] = NULL;
	return (0);
}

int	read_config(int fd, t_list **head)
{
	t_list	*new;
	char	*line;
	int		gnl_flag;

	gnl_flag = get_next_line(fd, &line);
	while (gnl_flag)
	{
		if (gnl_flag == -1)
			return (put_error(MEM_ERR, ERR_STD));
		new = ft_lstnew(line);
		if (!new)
			return (put_error(MEM_ERR, ERR_STD));
		ft_lstadd_back(head, new);
		gnl_flag = get_next_line(fd, &line);
	}
	new = ft_lstnew(line);
	if (!new)
		return (put_error(MEM_ERR, ERR_STD));
	ft_lstadd_back(head, new);
	return (0);
}

int	parse_config(t_data *all, t_list *cnfg_lst)
{
	int		i;

	i = -1;
	while (cnfg_lst)
	{
		if (((char *)(cnfg_lst->content))[0])
		{
			if (++i <= MAP)
			{
				if (check_id(i, all->cnfg, (char *)(cnfg_lst->content)) < 0)
					return (-1);
				if (i == MAP)
					if (parse_map(all, &cnfg_lst) < 0)
						return (-1);
			}
			else
				return (put_error(CONFIG_ERR, ERR_SYM_AFTER_MAP));
		}
		if (cnfg_lst)
			cnfg_lst = cnfg_lst->next;
	}
	if (i < MAP)
		return (put_error(CONFIG_ERR, ERR_MISSING_CONF_DATA));
	return (0);
}

int	parse_map(t_data *all, t_list **map_ptr)
{
	all->map_h = get_map_h(*map_ptr);
	all->map_width = 0;
	if (make_map_arr(all, map_ptr, all->map_h) < 0)
		return (-1);
	if (check_map_hor(all->map, all->plr_data, &all->map_width) < 0 || \
		make_rect_map(all->map, all->map_width) < 0 || \
		check_map_ver(all->map, all->map_width) < 0)
		return (-1);
	return (0);
}

void	parser(t_data *all)
{
	t_list	*cnfg_lst;

	cnfg_lst = NULL;
	if (read_config(all->fd, &cnfg_lst) < 0)
		shut_down(all);
	if (parse_config(all, cnfg_lst) < 0)
	{
		ft_lstclear(&cnfg_lst, free);
		shut_down(all);
	}
	ft_lstclear(&cnfg_lst, free);
}
