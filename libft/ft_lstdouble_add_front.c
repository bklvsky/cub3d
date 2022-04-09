/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdouble_add_front.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:54:52 by dselmy            #+#    #+#             */
/*   Updated: 2022/02/01 19:55:55 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdouble_add_front(t_lst_d **head, t_lst_d *new)
{
	if (head)
	{
		if (new)
		{
			if (*head)
				(*head)->prev = new;
			new->next = *head;
			new->prev = NULL;
			*head = new;
		}
	}
}
