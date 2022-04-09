/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_charmtrx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:08:05 by dselmy            #+#    #+#             */
/*   Updated: 2021/11/06 00:21:17 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_charmtrx(char **mtrx)
{
	int		i;

	i = -1;
	if (mtrx)
		while (mtrx[++i])
			free(mtrx[i]);
	free(mtrx);
}
