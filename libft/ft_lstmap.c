/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 22:59:53 by dselmy            #+#    #+#             */
/*   Updated: 2020/05/22 23:46:24 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (lst && f && del)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			return (NULL);
		tmp = new;
		while (lst->next)
		{
			lst = lst->next;
			tmp->next = ft_lstnew(f(lst->content));
			if (!tmp->next)
			{
				ft_lstclear(&(new), del);
				return (NULL);
			}
			tmp = tmp->next;
		}
		return (new);
	}
	return (NULL);
}
