/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 20:16:30 by dselmy            #+#    #+#             */
/*   Updated: 2021/12/25 20:20:00 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char *old, size_t new_size)
{
	char	*new;

	new = (char *)ft_calloc(new_size, sizeof(char));
	if (!new)
	{
		free(old);
		return (NULL);
	}
	ft_strlcpy(new, old, new_size);
	free(old);
	return (new);
}
