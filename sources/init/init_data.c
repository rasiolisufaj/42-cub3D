#include "../../includes/cub3d.h"

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

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	// init_player(&data->player);
	init_texinfo(&data->texinfo);
	data->map = NULL;
	init_mapinfo(&data->mapinfo);
	// init_img_clean(&data->minimap);
	data->texture_pixels = NULL;
	data->textures = NULL;
}
