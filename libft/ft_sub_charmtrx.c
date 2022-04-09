/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_charmtrx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:55:16 by dselmy            #+#    #+#             */
/*   Updated: 2021/11/06 00:18:08 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sub_charmtrx(char **src, int start, int len)
{
	char	**new;
	int		i;
	int		src_len;

	src_len = ft_charmtrx_len(src);
	if (src_len < start)
		return (NULL);
	if (src_len - start < len)
		len = src_len - start;
	new = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i++] = ft_strdup(src[start++]);
		if (!new[i - 1])
		{
			ft_free_charmtrx(new);
			return (NULL);
		}
	}
	return (new);
}
