/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:27:19 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/05 22:27:22 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_valid_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (err_msg_val(rgb[i], ERR_RGB_VAL, FAILURE));
		i++;
	}
	return (SUCCESS);
}

int	check_textures_validity(t_data *data, t_texinfo *textures)
{
	if (!textures->north || !textures->south || !textures->east
		|| !textures->west)
		return (err_msg(data->mapinfo.path, ERR_TEX_MISSING, FAILURE));
	if (!textures->floor || !textures->ceiling)
		return (err_msg(data->mapinfo.path, ERR_COLOR_MISSING, FAILURE));
	if (check_file(textures->north, false) == FAILURE
		|| check_file(textures->south, false) == FAILURE
		|| check_file(textures->east, false) == FAILURE
		|| check_file(textures->west, false) == FAILURE
		|| check_valid_rgb(textures->floor) == FAILURE
		|| check_valid_rgb(textures->ceiling) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
