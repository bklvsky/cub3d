/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 20:43:37 by dselmy            #+#    #+#             */
/*   Updated: 2021/09/19 23:47:10 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	unsigned long		value;
	int					sign;

	sign = 1;
	value = 0;
	while (*ptr == ' ' || (*ptr >= '\t' && *ptr <= '\r'))
		ptr += 1;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign = -1;
		ptr += 1;
	}
	while (ft_isdigit(*ptr))
	{
		value = 10 * value + (*ptr - '0');
		ptr += 1;
	}
	return ((int)(value * sign));
}
