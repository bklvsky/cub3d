/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 19:18:32 by dselmy            #+#    #+#             */
/*   Updated: 2021/09/24 22:14:16 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_remained_sym(char **line, char **storage)
{
	char	*p_new_line;
	char	*tmp;

	if (*storage)
	{
		p_new_line = ft_strchr(*storage, '\n');
		if (p_new_line)
		{
			*p_new_line = '\0';
			*line = ft_strdup(*storage);
			tmp = *storage;
			*storage = ft_strdup(p_new_line + 1);
			free(tmp);
			return (p_new_line);
		}
		else
		{
			*line = ft_strdup(*storage);
			free(*storage);
			*storage = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (NULL);
}

char	*add_buffer(char **line, char *buf, char **storage)
{
	char	*ptr;
	char	*tmp;

	ptr = ft_strchr(buf, '\n');
	if (ptr)
	{
		*ptr = '\0';
		*storage = ft_strdup(ptr + 1);
	}
	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(tmp);
	return (ptr);
}

int	get_next_line(int fd, char **line)
{
	static char	*storage;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*p_new_line;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) != 0)
		return (-1);
	p_new_line = get_remained_sym(line, &storage);
	if (!*line || (p_new_line && !storage))
		return (-1);
	while (!p_new_line)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (!bytes_read)
			break ;
		buf[bytes_read] = '\0';
		p_new_line = add_buffer(line, buf, &storage);
		if (!*line || (p_new_line && !storage))
			return (-1);
	}
	if (!p_new_line)
		return (0);
	return (1);
}
