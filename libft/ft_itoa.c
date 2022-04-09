/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:56:35 by dselmy            #+#    #+#             */
/*   Updated: 2021/09/20 00:49:52 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isnegative(int n)
{
	return (n < 0);
}

static int	get_length(int n, int neg)
{
	int		len;

	len = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		len += 1;
	}
	return (len + neg);
}

static int	abs_value(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*str;

	neg = isnegative(n);
	len = get_length(n, neg);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > neg)
	{
		str[len] = (abs_value(n % 10)) + '0';
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
