/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charmtrx_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:53:16 by dselmy            #+#    #+#             */
/*   Updated: 2021/11/06 00:20:14 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_charmtrx_len(char **mtrx)
{
	size_t	i;

	i = 0;
	if (!mtrx)
		return (-1);
	while (mtrx[i])
		i += 1;
	return (i);
}
