/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:27:49 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/08 15:58:49 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_img_clean(t_img *img)
{
	img->addr = NULL;
	img->img = NULL;
	img->bits_per_pixel = 0;
	img->size_line = 0;
	img->endian = 0;
}

static void	init_mapinfo(t_mapinfo *mapinfo)
{
	mapinfo->fd = 0;
	mapinfo->line_count = 0;
	mapinfo->path = NULL;
	mapinfo->file = NULL;
	mapinfo->height = 0;
	mapinfo->width = 0;
	mapinfo->index_end_of_map = 0;
}

static void	init_player(t_player *player)
{
	player->dir = '\0';
	player->has_moved = 0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	init_player(&data->player);
	init_texinfo(&data->texinfo);
	data->map = NULL;
	init_mapinfo(&data->mapinfo);
	// init_img_clean(&data->minimap);
	data->texture_pixels = NULL;
	data->textures = NULL;
}
