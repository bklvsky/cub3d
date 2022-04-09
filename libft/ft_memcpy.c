/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 10:23:10 by dselmy            #+#    #+#             */
/*   Updated: 2020/05/21 07:18:55 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_d;
	unsigned char	*temp_s;

	if (!dest && !src)
		return (NULL);
	temp_d = (unsigned char *)dest;
	temp_s = (unsigned char *)src;
	while (n > 0)
	{
		*temp_d = *temp_s;
		temp_d += 1;
		temp_s += 1;
		n--;
	}
	return (dest);
}
