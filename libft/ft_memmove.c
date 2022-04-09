/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 06:44:10 by dselmy            #+#    #+#             */
/*   Updated: 2020/05/21 07:16:34 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_d;
	unsigned char	*temp_s;

	if (!src && !dest)
		return (NULL);
	temp_d = (unsigned char *)dest;
	temp_s = (unsigned char *)src;
	if (temp_d < temp_s)
		while (n--)
			*temp_d++ = *temp_s++;
	else
	{
		temp_d += n - 1;
		temp_s += n - 1;
		while (n--)
		{
			*temp_d = *temp_s;
			temp_d -= 1;
			temp_s -= 1;
		}
	}
	return (dest);
}
