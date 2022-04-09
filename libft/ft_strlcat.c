/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 13:40:38 by dselmy            #+#    #+#             */
/*   Updated: 2022/01/28 20:24:05 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*ptr;
	size_t	d_len;

	ptr = (char *)src;
	d_len = ft_strlen(dst);
	dst += d_len;
	while (*ptr && size > d_len + 1)
	{
		*dst++ = *ptr++;
		size--;
	}
	if (size > d_len)
		*dst = '\0';
	if (size < d_len)
		return (size + ft_strlen(src));
	return (d_len + ft_strlen(src));
}
