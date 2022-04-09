/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 17:48:21 by dselmy            #+#    #+#             */
/*   Updated: 2020/05/08 18:00:16 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*temp;

	temp = (char *)str + ft_strlen(str);
	while (temp != str && *temp != (char)c)
		temp--;
	if (*temp == (char)c)
		return (temp);
	return (NULL);
}
