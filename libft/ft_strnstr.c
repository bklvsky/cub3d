/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 23:17:21 by dselmy            #+#    #+#             */
/*   Updated: 2020/05/08 23:59:45 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		b;
	size_t		l;
	char		*temp;

	b = 0;
	temp = (char *)big;
	if (!little[0])
		return (temp);
	while (temp[b] && b < len)
	{
		l = 0;
		while (temp[b] && temp[b] != little[l] && b < len)
			b++;
		while (temp[b] == little[l] && little[l] && b < len)
		{
			b++;
			l++;
		}
		if (!little[l])
			return (&temp[b - l]);
	}
	return (NULL);
}
