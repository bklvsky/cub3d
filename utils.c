/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:16:23 by dselmy            #+#    #+#             */
/*   Updated: 2021/08/03 02:50:00 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_file_format(char *file_name, char *format)
{
	int		form_len;
	int		file_name_len;

	form_len = ft_strlen(format);
	file_name_len = ft_strlen(file_name);
	if (ft_strncmp(file_name + file_name_len - form_len, format, form_len + 1) != 0)
		return (0);
	return (1);
}

int		only_num(const char *line)
{
	char	*ptr;
	
	ptr = (char *)line;
	while (*ptr && ft_isdigit(*ptr))
		ptr++;
	if (!*ptr)
		return (1);
	else
		return (0);
}

void	free_arr(char **arr)
{
	int		i;
	
	i = -1;
	if (arr)
		while (arr[++i])
			free(arr[i]);
	free(arr);	
}

int		set_flag(int *flag)
{
	if (*flag == 0)
	{
		*flag = 1;
		return (1);
	}
	else
		return (0);		
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}