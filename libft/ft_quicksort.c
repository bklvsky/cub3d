/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 02:46:03 by dselmy            #+#    #+#             */
/*   Updated: 2021/11/09 00:46:17 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap_int(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_quicksort(int *array, int left, int right)
{
	int		mid;
	int		l;
	int		r;

	mid = array[left + (right - left) / 2];
	l = left;
	r = right;
	while (l < r)
	{
		while (array[l] < mid)
			l++;
		while (array[r] > mid)
			r--;
		if (l <= r)
		{
			ft_swap_int(&(array[l]), &(array[r]));
			r -= 1;
			l += 1;
		}
	}
	if (l < right)
		ft_quicksort(array, l, right);
	if (r > left)
		ft_quicksort(array, left, r);
}
