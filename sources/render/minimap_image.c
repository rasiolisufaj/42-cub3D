#include "cub3d.h"

void	draw_pixel(t_data *data, int x, int y, int size, int color)
{
	int i;
	int j;
	
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

int  detect_wall(float y, float x, t_data *data)
{
    if (data->map[(int)y][(int)x] == '1')
        return 1;
    return 0;
}

int handle_key(int key_code, t_data *data)
{
    mlx_destroy_image(data->mlx, data->minimap.img);
    mlx_clear_window(data->mlx, data->win);
    if (key_code == 65307)
    {
        free_data(data);
        exit(0);
    }
    if (key_code == 119) // W
    {
        data->player.pos_y -= 0.5; 
        if (detect_wall(data->player.pos_y, data->player.pos_x, data) == 1)
            data->player.pos_y += 0.5;
        printf("W\n");
    }
    if (key_code == 97) // A
    {
        data->player.pos_x -= 0.5;
        if (detect_wall(data->player.pos_y, data->player.pos_x, data) == 1)
            data->player.pos_x += 0.5;
        printf("A\n");
    }
    if (key_code == 115) // S
    {
       data->player.pos_y += 0.5;
        if (detect_wall(data->player.pos_y, data->player.pos_x, data) == 1)
            data->player.pos_y -= 0.5;
       printf("S\n");
    }
    if (key_code == 100) // D
    {
        data->player.pos_x += 0.5;
        if (detect_wall(data->player.pos_y, data->player.pos_x, data) == 1)
            data->player.pos_x -= 0.5;
        printf("D\n");
    }
    draw_map(data, 40);
    draw_player(data, 10);
    return 0;
}