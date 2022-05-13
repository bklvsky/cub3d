/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:25:18 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/13 04:49:54 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	make_map_arr(t_data *all, t_list **map_ptr, int map_h)
{
	int		i;

	i = -1;
	all->map = (char **)malloc(sizeof(char *) * (map_h + 1));
	if (!all->map)
		return (ERR_STD);
	while (*map_ptr && ++i < map_h)
	{
		all->map[i] = ft_strdup((char *)(*map_ptr)->content);
		if (!all->map[i])
			return (ERR_STD);
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
			return (ERR_STD);
		new = ft_lstnew(line);
		if (!new)
			return (ERR_STD);
		ft_lstadd_back(head, new);
		gnl_flag = get_next_line(fd, &line);
	}
	new = ft_lstnew(line);
	if (!new)
		return (ERR_STD);
	ft_lstadd_back(head, new);
	return (0);
}

int	parse_config(t_data *all, t_list *cnfg_lst)
{
	t_list	*tmp;
	int		err;
	int		counter;

	tmp = cnfg_lst;
	counter = -1;
	while (tmp)
	{
		if (((char *)(tmp->content))[0])
		{
			if (++counter <= 6)
			{
				err = check_id(counter, all->cnfg, (char *)(tmp->content));
				if (err == 1)
					err = parse_map(all, &tmp);
				if (err < 0)
					return (err);
			}
			else
				return (ERR_SYM_AFTER_MAP);
		}
		if (tmp)
			tmp = tmp->next;
	}
	return (0);
}

int	parse_map(t_data *all, t_list **map_ptr)
{
	int		err_flag;

	all->cnfg->data[MAP] = 1;
	all->map_h = get_map_h(*map_ptr);
	all->map_width = 0;
	if (make_map_arr(all, map_ptr, all->map_h) < 0)
		return (ERR_STD);
	err_flag = check_map_hor(all->map, all->plr_data, &all->map_width);
	if (err_flag)
		return (err_flag);
	if (make_rect_map(all->map, all->map_width) < 0)
		return (ERR_STD);
	err_flag = check_map_ver(all->map, all->map_width);
	return (err_flag);
}

void	parser(t_data *all)
{
	t_list	*cnfg_lst;
	int		err_flag;

	cnfg_lst = NULL;
	err_flag = read_config(all->fd, &cnfg_lst);
	if (err_flag < 0)
		shut_down(all, err_flag);
	err_flag = parse_config(all, cnfg_lst);
	if (err_flag < 0)
	{
		ft_lstclear(&cnfg_lst, free);
		shut_down(all, err_flag);
	}
	ft_lstclear(&cnfg_lst, free);
}
