/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 23:21:31 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/14 23:21:31 by raisufaj         ###   ########.fr       */
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

t_draw_square	draw_init(int x, int y, int size, int color)
{
	t_draw_square	p;

	p.x = x;
	p.y = y;
	p.size = size;
	p.color = color;
	return (p);
}

void	draw_square(t_data *data, t_draw_square p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p.size)
	{
		j = 0;
		while (j < p.size)
		{
			my_mlx_pixel_put(data, p.x + i, p.y + j, p.color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data, int size)
{
	t_draw_square	p;

	p.x = 135;
	p.y = 75;
	p.size = size;
	p.color = PLAYER_COLOR;
	draw_square(data, p);
}
