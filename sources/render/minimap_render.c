/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:55:29 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/14 21:55:29 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_minimap_border(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_HEIGHT)
	{
		j = 0;
		while (j < MINIMAP_WIDTH)
		{
			if (i == 0 || j == 0 || i >= MINIMAP_HEIGHT - MINIMAP_BORDER
				|| j >= MINIMAP_WIDTH - MINIMAP_BORDER)
				draw_pixel(data, j, i, MINIMAP_BORDER, MINIMAP_COLOR);
			j += MINIMAP_BORDER;
		}
		i += MINIMAP_BORDER;
	}
}

static void	draw_tile_border(t_data *data, int x, int y, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		my_mlx_pixel_put(data, x + i, y, MINIMAP_COLOR);
		my_mlx_pixel_put(data, x + i, y + size - 1, MINIMAP_COLOR);
		my_mlx_pixel_put(data, x, y + i, MINIMAP_COLOR);
		my_mlx_pixel_put(data, x + size - 1, y + i, MINIMAP_COLOR);
		i++;
	}
}

static void	draw_map_tiles(t_data *data, int tile_size, int offset_x,
		int offset_y)
{
	int	x;
	int	y;
	int	x_final;
	int	y_final;

	y = 0;
	while (y < data->mapinfo.height)
	{
		x = 0;
		while (x < data->mapinfo.width)
		{
			x_final = (x * tile_size) + offset_x;
			y_final = (y * tile_size) + offset_y;
			if (is_tile_visible(x_final, y_final, tile_size))
			{
				draw_tile_border(data, x_final, y_final, tile_size);
				if (data->map[y][x] == '1')
					draw_pixel(data, x_final, y_final, tile_size,
						MINIMAP_COLOR);
			}
			x++;
		}
		y++;
	}
}

void	draw_map(t_data *data, int tile_size)
{
	int	offset_x;
	int	offset_y;

	offset_x = (int)(140 - (data->player.pos_x * tile_size));
	offset_y = (int)(80 - (data->player.pos_y * tile_size));
	init_minimap_image(data);
	draw_minimap_border(data);
	draw_map_tiles(data, tile_size, offset_x, offset_y);
	draw_player(data, 10);
	mlx_put_image_to_window(data->mlx, data->win, data->minimap.img, 0, 0);
}

int	render_minimap(t_data *data)
{
	double	speed;
	double	new_x;
	double	new_y;

	speed = 0.003;
	if (data->minimap.img)
		mlx_destroy_image(data->mlx, data->minimap.img);
	data->minimap.img = NULL;
	if (data->player.move_y)
	{
		new_y = data->player.pos_y + (data->player.move_y * speed);
		if (validate_move(data, data->player.pos_x, new_y)
			&& !detect_wall(data->player.pos_x, new_y, data))
			data->player.pos_y = new_y;
	}
	if (data->player.move_x)
	{
		new_x = data->player.pos_x + (data->player.move_x * speed);
		if (validate_move(data, new_x, data->player.pos_y)
			&& !detect_wall(new_x, data->player.pos_y, data))
			data->player.pos_x = new_x;
	}
	draw_map(data, 50);
	return (0);
}
