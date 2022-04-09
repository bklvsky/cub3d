/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdouble_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:01:52 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/01 20:02:07 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstdouble_size(t_lst_d *lst)
{
	int		size;
	t_lst_d	*tmp;

	size = 0;
	tmp = lst;
	while (tmp)
	{
		size += 1;
		tmp = tmp->next;
	}
	return (size);
}
