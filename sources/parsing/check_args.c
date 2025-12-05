/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:27:08 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/05 22:27:11 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Checks whether the arg given is a correct .cub extension */

static bool	is_dir(char *arg)
{
	int		fd;
	bool	retval;

	retval = false;
	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		retval = true;
	}
	return (retval);
}

static bool	is_cub_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if (len < 5)
		return (false);
	if ((arg[len - 4] != '.' || arg[len - 3] != 'c' || arg[len - 2] != 'u'
			|| arg[len - 1] != 'b'))
		return (false);
	return (true);
}

static bool	is_xpm_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if (len < 5)
		return (false);
	if ((arg[len - 4] != '.' || arg[len - 3] != 'x' || arg[len - 2] != 'p'
			|| arg[len - 1] != 'm'))
		return (false);
	return (true);
}

int	check_file(char *arg, bool cub)
{
	int	fd;

	if (is_dir(arg))
		return (err_msg(arg, ERR_FILE_IS_DIR, FAILURE));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (err_msg(arg, strerror(errno), FAILURE));
	close(fd);
	if (cub && !is_cub_file(arg))
		return (err_msg(arg, ERR_FILE_NOT_CUB, FAILURE));
	if (!cub && !is_xpm_file(arg))
		return (err_msg(arg, ERR_FILE_NOT_XPM, FAILURE));
	return (0);
}
