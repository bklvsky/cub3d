/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdouble_clear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:01:10 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/01 20:01:28 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdouble_clear(t_lst_d **lst, void (*del)(void *))
{
	t_lst_d	*tmp;

	if (lst && del && *lst)
	{
		while ((*lst)->next)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			ft_lstdouble_delone(tmp, del);
		}
		ft_lstdouble_delone(*lst, del);
		*lst = NULL;
	}
}
