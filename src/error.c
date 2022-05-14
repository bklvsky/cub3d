/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:40:25 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/15 01:58:49 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*manage_arg_errors(int error)
{
	if (error == ERR_ARG_NO_FILE)
		return ("no scene desription file supplied.");
	else if (error == ERR_TOO_MANY_ARG)
		return ("too many arguments.");
	else if (error == ERR_ARG_FORMAT)
		return ("wrong scene description file format.");
	else
		return ("unknown argument.");
}

static char	*manage_config_errors(int error)
{
	if (error == ERR_MISSING_CONF_DATA)
		return ("incomplete scene configuration data.");
	else if (error == ERR_RESOLUTION)
		return ("wrong resolution data formatting (256x256).");
	else if (error == ERR_TEX_FORMAT)
		return ("wrong texture file format (.xpm is required).");
	else if (error == ERR_COLOR)
		return ("wrong color configuration data.");
	else if (error == ERR_UNKNOWN_SYM_MAP)
		return ("uknown symbol in the map.");
	else if (error == ERR_SYM_AFTER_MAP)
		return ("symbols after the map.");
	else if (error == ERR_UKNOWN_SYM)
		return ("identifiers error or identifiers in the wrong order.");
	else if (error == ERR_NOT_CLOSED_MAP)
		return ("the map is not closed.");
	else if (error == ERR_DUPL_DATA)
		return ("configuration data duplicated.");
	else if (error == ERR_NO_PLR)
		return ("player not found.");
	else
		return ("multiple players encountered.");
}

static char	*get_error(int error)
{
	if (error == ERR_STD)
		return (strerror(errno));
	if (error >= ERR_ARG_UNKNOWN)
		return (manage_arg_errors(error));
	else
		return (manage_config_errors(error));
}

int	put_error(char *error_cause, int error)
{
	ft_putendl_fd("Error", 2);
	if (error_cause)
	{
		ft_putstr_fd(error_cause, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(get_error(error), 2);
	return (-1);
}
