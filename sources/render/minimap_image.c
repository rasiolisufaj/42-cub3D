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
        data->player.pos_y -= 1; 
        printf("W\n");
    }
    if (key_code == 97) // A
    {
        data->player.pos_x -= 1;
        printf("A\n");
    }
    if (key_code == 115) // S
    {
       data->player.pos_y += 1;
       printf("S\n");
    }
    if (key_code == 100) // D
    {
        data->player.pos_x += 1;
        printf("D\n");
    }
    draw_map(data, 20);
    draw_player(data, 5);
    return 0;
}