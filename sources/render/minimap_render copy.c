/*#include "cub3d.h"


static void	draw_border_top(t_data *data, int x_final, int y_final,
		int tile_size)
{
	int i;

	i = 0;
	while (i < tile_size)
	{
		my_mlx_pixel_put(data, x_final + i, y_final, 0x00FFFFFF);
		i++;
	}
}

static void	draw_border_bottom(t_data *data, int x_final, int y_final,
		int tile_size)
{
	int i;

	i = 0;
	while (i < tile_size)
	{
		my_mlx_pixel_put(data, x_final + i, y_final + tile_size - 1,
			0x00FFFFFF);
		i++;
	}
}

static void	draw_border_left(t_data *data, int x_final, int y_final,
		int tile_size)
{
	int i;

	i = 0;
	while (i < tile_size)
	{
		my_mlx_pixel_put(data, x_final, y_final + i, 0x00FFFFFF);
		i++;
	}
}

static void	draw_border_right(t_data *data, int x_final, int y_final,
		int tile_size)
{
	int i;

	i = 0;
	while (i < tile_size)
	{
		my_mlx_pixel_put(data, x_final + tile_size - 1, y_final + i,
			0x00FFFFFF);
		i++;
	}
}

static void	draw_tile_borders(t_data *data, int x_final, int y_final,
		int tile_size)
{
	draw_border_top(data, x_final, y_final, tile_size);
	draw_border_bottom(data, x_final, y_final, tile_size);
	draw_border_left(data, x_final, y_final, tile_size);
	draw_border_right(data, x_final, y_final, tile_size);
}

void	draw_map_side(int width, int height, t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((i == 0 || j == 0) || (i >= height - 5 || j >= width - 5))
				draw_pixel(data, j, i, 5, 0x00FFFFFF);
			j += 5;
		}
		i += 5;
	}
}

static void	render_tile(t_data *data, int x, int y, int x_final, int y_final,
		int tile_size)
{
	if (x_final >= -tile_size && x_final < 280 && y_final >= -tile_size
		&& y_final < 160)
	{
		draw_tile_borders(data, x_final, y_final, tile_size);
		if (data->map[y][x] == '1')
			draw_pixel(data, x_final, y_final, tile_size, 0x00FFFFFF);
	}
}

static void	render_all_tiles(t_data *data, int tile_size, int offset_x,
		int offset_y)
{
	int x;
	int y;
	int x_final;
	int y_final;

	y = 0;
	while (y < data->mapinfo.height)
	{
		x = 0;
		while (x < data->mapinfo.width)
		{
			x_final = (x * tile_size) + offset_x;
			y_final = (y * tile_size) + offset_y;
			render_tile(data, x, y, x_final, y_final, tile_size);
			x++;
		}
		y++;
	}
}

static void	init_minimap_image(t_data *data)
{
	data->minimap.img = mlx_new_image(data->mlx, 280, 160);
	data->minimap.addr = (int *)mlx_get_data_addr(data->minimap.img,
			&data->minimap.bits_per_pixel, &data->minimap.size_line,
			&data->minimap.endian);
}

void	draw_map(t_data *data, int tile_size)
{
	int offset_x;
	int offset_y;

	offset_x = (int)(140 - (data->player.pos_x * tile_size));
	offset_y = (int)(80 - (data->player.pos_y * tile_size));
	init_minimap_image(data);
	draw_map_side(280, 160, data);
	render_all_tiles(data, tile_size, offset_x, offset_y);
	draw_player(data, 10);
	mlx_put_image_to_window(data->mlx, data->win, data->minimap.img, 0, 0);
}

void	draw_player(t_data *data, int size)
{
	int center_x;
	int center_y;

	center_x = 135;
	center_y = 75;
	draw_pixel(data, center_x, center_y, size, 0x00FF0000);
}

static void	update_player_movement_y(t_data *data, double speed)
{
	double new_y;

	if (data->player.move_y != 0)
	{
		new_y = data->player.pos_y + (data->player.move_y * speed);
		if (validate_move(data, data->player.pos_x, new_y) == 1)
		{
			if (detect_wall(new_y, data->player.pos_x, data) == 0)
				data->player.pos_y = new_y;
		}
	}
}

static void	update_player_movement_x(t_data *data, double speed)
{
	double new_x;

	if (data->player.move_x != 0)
	{
		new_x = data->player.pos_x + (data->player.move_x * speed);
		if (validate_move(data, new_x, data->player.pos_y) == 1)
		{
			if (detect_wall(data->player.pos_y, new_x, data) == 0)
				data->player.pos_x = new_x;
		}
	}
}

int	render_minimap(t_data *data)
{
	double speed;

	speed = 0.003;
	if (data->minimap.img)
		mlx_destroy_image(data->mlx, data->minimap.img);
	data->minimap.img = NULL;
	update_player_movement_y(data, speed);
	update_player_movement_x(data, speed);
	draw_map(data, 50);
	draw_player(data, 10);
	return (0);
}
*/
