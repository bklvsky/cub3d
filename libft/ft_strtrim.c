/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 23:14:39 by dselmy            #+#    #+#             */
/*   Updated: 2020/05/25 19:18:38 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;
	char	*result;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	else
	{
		end = ft_strlen(s1);
		start = 0;
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (end > start && ft_strchr(set, s1[end]))
			end--;
		result = ft_substr(s1, start, end - start + 1);
		return (result);
	}
}
