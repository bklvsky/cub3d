/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_charmtrx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:00:00 by dselmy            #+#    #+#             */
/*   Updated: 2022/01/04 01:25:31 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc_charmtrx(char **arr, size_t size)
{
	char		**new;
	size_t		y;

	new = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!new)
		return (NULL);
	if (!arr)
		return (new);
	y = 0;
	while (arr[y] && y < size)
	{
		new[y] = arr[y];
		y += 1;
	}
	free(arr);
	return (new);
}
