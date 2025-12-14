#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 280 || y < 0 || y >= 160)
		return ;
	dst = (char *)data->minimap.addr + (y * data->minimap.size_line + x
			* (data->minimap.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_map_side(int width, int height, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
/*real mode*/
// void	draw_map(t_data *data, int tile_size)
// {
// 	int		offset_x;
// 	int		offset_y;
// 	int		x_final;
// 	int		y_final;
// 	int 	x;
// 	int 	y;

// 	y = 0;
// 	offset_x = (int)(140 - (data->player.pos_x * tile_size));
// 	offset_y = (int)(80 - (data->player.pos_y * tile_size));
// 	data->minimap.img = mlx_new_image(data->mlx, 280, 160);
// 	data->minimap.addr = (int *)mlx_get_data_addr(data->minimap.img,
// 			&data->minimap.bits_per_pixel, &data->minimap.size_line,
// 			&data->minimap.endian);
// 	draw_map_side(280, 160, data);
// 	while (y < data->mapinfo.height)
// 	{
// 		x = 0;
// 		while (x < data->mapinfo.width)
// 		{
// 			x_final = (x * tile_size) + offset_x;
// 			y_final = (y * tile_size) + offset_y;
			
// 			if (data->map[y][x] == '1')
// 			{
// 				if (x_final >= 0 && x_final < 280 && y_final >= 0 && y_final < 160)
// 					draw_pixel(data, x_final, y_final, tile_size, 0x00FFFFFF);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	draw_player(data, 10);
// 	mlx_put_image_to_window(data->mlx, data->win, data->minimap.img, 0, 0);
// }

// /*debug mode*/
void	draw_map(t_data *data, int tile_size)
{
    int		offset_x;
    int		offset_y;
    int		x_final;
    int		y_final;
    int 	x;
    int 	y;
    int		i;

    y = 0;
    offset_x = (int)(140 - (data->player.pos_x * tile_size));
    offset_y = (int)(80 - (data->player.pos_y * tile_size));
    data->minimap.img = mlx_new_image(data->mlx, 280, 160);
    data->minimap.addr = (int *)mlx_get_data_addr(data->minimap.img,
            &data->minimap.bits_per_pixel, &data->minimap.size_line,
            &data->minimap.endian);
    draw_map_side(280, 160, data);
    while (y < data->mapinfo.height)
    {
        x = 0;
        while (x < data->mapinfo.width)
        {
            x_final = (x * tile_size) + offset_x;
            y_final = (y * tile_size) + offset_y;
            
            if (x_final >= -tile_size && x_final < 280 && y_final >= -tile_size && y_final < 160)
            {
                // Draw top border
                for (i = 0; i < tile_size; i++)
                    my_mlx_pixel_put(data, x_final + i, y_final, 0x00FFFFFF);
                // Draw bottom border
                for (i = 0; i < tile_size; i++)
                    my_mlx_pixel_put(data, x_final + i, y_final + tile_size - 1, 0x00FFFFFF);
                // Draw left border
                for (i = 0; i < tile_size; i++)
                    my_mlx_pixel_put(data, x_final, y_final + i, 0x00FFFFFF);
                // Draw right border
                for (i = 0; i < tile_size; i++)
                    my_mlx_pixel_put(data, x_final + tile_size - 1, y_final + i, 0x00FFFFFF);
                
                // Fill wall tiles if it's a '1'
                if (data->map[y][x] == '1')
                    draw_pixel(data, x_final, y_final, tile_size, 0x00FFFFFF);
            }
            x++;
        }
        y++;
    }
    draw_player(data, 10);
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
