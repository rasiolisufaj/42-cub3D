#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = (char *)data->minimap.addr + (y * data->minimap.size_line + x
			* (data->minimap.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_map_side(int width, int height, t_data *data, int tile_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)tile_size;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((i == 0 || j == 0) || (i >= height - 5 || j >= width - 5))
				draw_pixel(data, j , i, 5, 0x00FFFFFF);
			j += 5;
		}
		i += 5;
	}
}

void	draw_map(t_data *data, int size)
{
	int		tile_size;
	int		offset_x;
	int		offset_y;
	int		c_y;
	int		c_x;
	int		x_final;
	int		y_final;
	int x = 0;
	int y = 0;

	(void)size;
	tile_size = 25;
	c_y = 80;
	c_x = 140;
	offset_x = (int)(c_x - (data->player.pos_x * tile_size));
	offset_y = (int)(c_y - (data->player.pos_y * tile_size));
	data->minimap.img = mlx_new_image(data->mlx, 280, 160);
	data->minimap.addr = (int *)mlx_get_data_addr(data->minimap.img,
			&data->minimap.bits_per_pixel, &data->minimap.size_line,
			&data->minimap.endian);
	draw_map_side(280, 160, data, tile_size);
	while (y < data->mapinfo.height)
	{
		x = 0;
		while (x < data->mapinfo.width)
		{
			if (data->map[y][x] == '1')
			{
				x_final = (x * tile_size) + offset_x;
				y_final = (y * tile_size) + offset_y;
				// x_final = (data->player.pos_x * tile_size);
				// y_final = (data->player.pos_y * tile_size);
				if (x_final >= 0 && x_final < 280 && y_final >= 0 && y_final < 160)
					draw_pixel(data, x_final, y_final, tile_size, 0x00FFFFFF);
			}
			x++;
		}
		y++;
	}
	draw_player(data, 5);
	mlx_put_image_to_window(data->mlx, data->win, data->minimap.img, 0, 0);
}

void	draw_player(t_data *data, int size)
{
	int	center_x;
	int	center_y;

	center_x = 140;
	center_y = 80;
	draw_pixel(data, center_x, center_y, size, 0x00FF0000);
}

// void	draw_map(t_data *data, int size)
// {
// 	data->minimap.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
// 	data->minimap.addr = (int *)mlx_get_data_addr(data->minimap.img,
// 			&data->minimap.bits_per_pixel, &data->minimap.size_line,
// 			&data->minimap.endian);
// 	my_mlx_pixel_put(data, 200, 200, 0x00FF0000);
// 	mlx_put_image_to_window(data->mlx, data->win, data->minimap.img, 0, 0);
// 	// printf("%d\n", data->mapinfo.width);
// 	// printf("%d\n", data->mapinfo.height);
// 	(void)size;
// }