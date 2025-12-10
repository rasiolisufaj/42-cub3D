#include "cub3d.h"

void	draw_map(t_data *data, int size)
{
	int i;
	int j;
	int tile_size;
	// int x_map;
	// int y_map;
	// int offset_x;
	// int offset_y;
	// int c_y;
	// int c_x;

	tile_size = 20;
	// c_y = 6.5 * tile_size;
	// c_x = 4 * tile_size;
	i = 0;
	// offset_x = c_x - data->player.pos_x;
	// offset_y = c_y - data->player.pos_y;
	// x_map = data->player.pos_x * tile_size;
	// y_map = data->player.pos_y * tile_size;
	// printf("x = %d\ny = %d\n", x_map, y_map);
	// printf("%d\n", data->mapinfo.height);
	// printf("%d\n", data->mapinfo.width);
	while (i < 14)
	{
		j = 0;
		while (j < 8)
		{
			if ((i == 0 || j == 0) || (i == 13 || j == 7))
			{
				draw_pixel(data, i * tile_size, j * tile_size, size, 0x00FFFFFF);
			}
			j++;
		}
		i++;
	}
	// // data->map_width = 14, data->map_height = 8 (Exemples)
	// int map_height = 14;
	// int map_width = 8;
	// int y_map = 0;
	// while (y_map < map_height) // Boucle sur les lignes (Y)
	// {
	// 	int x_map = 0;
	// 	while (x_map < map_width) // Boucle sur les colonnes (X)
	// 	{
	// 		// 1. Calculer la position du coin supérieur gauche du bloc (x_map, y_map) après translation
	// 		int X_final = (x_map * tile_size) + offset_x;
	// 		int Y_final = (y_map * tile_size) + offset_y;

	// 		// 2. Vérifier si le bloc est un mur (ou un espace vide)
	// 		if (data->map[y_map][x_map] == '1' || data->map[y_map][x_map] == '0')
	// 		{
	// 			// 3. Dessiner le bloc avec Clipping
	// 			// Appeler une fonction qui dessine le carré en respectant les limites du HUD
	// 			draw_clipped_tile(data, X_final, Y_final, tile_size);
	// 		}
	// 		x_map++;
	// 	}
	// 	y_map++;
	// }
}

void	draw_player(t_data *data, int size)
{
    int tile_size;
    int center_x;
    int center_y;

    tile_size = 20;
    center_x = 6.5 * tile_size;
    center_y = 4 * tile_size;
    
    draw_pixel(data, center_x, center_y, size, 0x00FF0000);
}