/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:27:44 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/11 14:17:00 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

static void	free_texinfo(t_texinfo *textures)
{
	if (textures->north)
		free(textures->north);
	if (textures->south)
		free(textures->south);
	if (textures->west)
		free(textures->west);
	if (textures->east)
		free(textures->east);
	if (textures->ceiling)
	{
		free(textures->ceiling);
		textures->ceiling = NULL;
	}
	if (textures->floor)
	{
		free(textures->floor);
		textures->floor = NULL;
	}
}

static void	free_map(t_data *data)
{
	if (data->mapinfo.fd > 0)
		close(data->mapinfo.fd);
	if (data->mapinfo.file)
		free_tab((void **)data->mapinfo.file);
	if (data->map)
		free_tab((void **)data->map);
}

static void	free_mlx(t_data *data)
{
	if (!data || !data->mlx)
		return ;
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->minimap.img)
	{
		mlx_destroy_image(data->mlx, data->minimap.img);
		data->minimap.img = NULL;
	}
	mlx_destroy_display(data->mlx);
	mlx_loop_end(data->mlx);
	free(data->mlx);
	data->mlx = NULL;
}

int	free_data(t_data *data)
{
	if (!data)
		return (FAILURE);
	free_mlx(data);
	if (data->textures)
		free_tab((void **)data->textures);
	// if (data->texture_pixels)
	// 	free_tab((void **)data->texture_pixels);
	free_texinfo(&data->texinfo);
	free_map(data);
	return (FAILURE);
}
