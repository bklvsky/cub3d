/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdouble_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:57:31 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/01 19:57:56 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst_d	*ft_lstdouble_new(void *elem)
{
	t_lst_d	*new;

	new = (t_lst_d *)malloc(sizeof(t_lst_d));
	if (!new)
		return (NULL);
	if (elem)
		new->content = elem;
	else
		new->content = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
