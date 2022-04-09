/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 07:31:50 by dselmy            #+#    #+#             */
/*   Updated: 2020/05/08 07:36:59 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	s;

	s = (unsigned char)c;
	tmp = (unsigned char *)dest;
	while (n--)
	{
		*tmp = s;
		tmp = tmp + 1;
	}
	return (dest);
}
