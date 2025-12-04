#include "../../includes/cub3d.h"

static int	check_map_is_last(t_mapinfo *map)
{
	int	i;
	int	j;

	i = map->index_end_of_map;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (is_whitespace(map->file[i][j]) == FAILURE)
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_map_validity(t_data *data, char **map_tab)
{
	if (!data->map)
		return (err_msg(data->mapinfo.path, ERR_MAP_MISSING, FAILURE));
	if (check_map_borders(&data->mapinfo, map_tab) == FAILURE)
		return (err_msg(data->mapinfo.path, ERR_MAP_NO_WALLS, FAILURE));
	if (data->mapinfo.height < 3)
		return (err_msg(data->mapinfo.path, ERR_MAP_TOO_SMALL, FAILURE));
	// if (check_map_elements(data, map_tab) == FAILURE)
	// 	return (FAILURE);
	// if (check_player_position(data, map_tab) == FAILURE)
	// 	return (FAILURE);
	if (check_map_is_last(&data->mapinfo) == FAILURE)
		return (err_msg(data->mapinfo.path, ERR_MAP_LAST, FAILURE));
	return (SUCCESS);
}
