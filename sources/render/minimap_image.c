/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:05:16 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/14 22:05:16 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_minimap_image(t_data *data)
{
	data->minimap.img = mlx_new_image(data->mlx, MINIMAP_WIDTH,
			MINIMAP_HEIGHT);
	data->minimap.addr = (int *)mlx_get_data_addr(data->minimap.img,
			&data->minimap.bits_per_pixel, &data->minimap.size_line,
			&data->minimap.endian);
}

void	draw_pixel(t_data *data, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data, int size)
{
	draw_pixel(data, 135, 75, size, PLAYER_COLOR);
}
