/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 23:37:45 by dselmy            #+#    #+#             */
/*   Updated: 2020/05/24 22:22:15 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*ptr;

	if (!src)
		return (0);
	ptr = (char *)src;
	while (size > 1 && *ptr)
	{
		*dst++ = *ptr++;
		size--;
	}
	if (size != 0)
		*dst = '\0';
	return (ft_strlen(src));
}
