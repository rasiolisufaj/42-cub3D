/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:27:56 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/08 15:49:17 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Turns an XPM texture file into our own pixel array so the raycaster can
access colors easily.
*/

static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;
	int		size;

	size = data->texinfo.size;
	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1, sizeof * buffer * size * size);
	if (!buffer)
		clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			buffer[y * size + x] = tmp.addr[y * size + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		clean_exit(data, err_msg(NULL, ERR_MALLOC, 1));
	data->textures[NORTH] = xpm_to_img(data, data->texinfo.north);
	data->textures[SOUTH] = xpm_to_img(data, data->texinfo.north);
	data->textures[EAST] = xpm_to_img(data, data->texinfo.north);
	data->textures[WEST] = xpm_to_img(data, data->texinfo.north);
}

void	init_texinfo(t_texinfo *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->size = TEX_SIZE;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}
