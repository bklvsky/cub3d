/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charmtrx_trim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:57:17 by dselmy            #+#    #+#             */
/*   Updated: 2021/11/06 00:20:18 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_charmtrx_trim(char **mtrx)
{
	char	**new;
	int		y;
	int		start;

	y = 0;
	while (mtrx[y] && mtrx[y][0] == '\0')
		y += 1;
	start = y;
	while (mtrx[y] && mtrx[y][0])
		y += 1;
	if (start == 0 && mtrx[y] == NULL)
		return (mtrx);
	new = ft_sub_charmtrx(mtrx, start, y - start);
	ft_free_charmtrx(mtrx);
	if (!new)
		return (NULL);
	return (new);
}
