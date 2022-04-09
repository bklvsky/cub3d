/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 22:52:05 by dselmy            #+#    #+#             */
/*   Updated: 2021/09/20 00:50:41 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(char const *str)
{
	size_t	len;

	if (!str)
		len = 0;
	else
		len = ft_strlen(str);
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;
	char	*start;

	if (!s1 && !s2)
		return (NULL);
	len1 = get_len(s1);
	len2 = get_len(s2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	start = res;
	if (s1)
		while (*s1)
			*(res++) = *(s1++);
	if (s2)
		while (*s2)
			*(res++) = *(s2++);
	*res = '\0';
	return (start);
}
