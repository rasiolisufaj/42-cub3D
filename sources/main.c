#include "../includes/cub3d.h"

static int	parse_args(t_data *data, char **av)
{
	if (check_file(av[1], true) == FAILURE)
		clean_exit(data, FAILURE);
	parse_data(av[1], data);
	if (get_file_data(data, data->mapinfo.file) == FAILURE)
		return (free_data(data));
	if (check_textures_validity(data, &data->texinfo) == FAILURE)
		return (free_data(data));
	return (0);
}

void	init_textures(t_texinfo *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->ceiling = NULL;
	texture->floor = NULL;
	texture->size = 0;
	texture->index = 0;
	texture->step = 0;
	texture->pos = 0;
	texture->x = 0;
	texture->y = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (err_msg("Usage", ERR_USAGE, 1));
	init_textures(&data.texinfo);
	if (parse_args(&data, av) != SUCCESS)
		return (1);
	free_data(&data);
	return (0);
}
