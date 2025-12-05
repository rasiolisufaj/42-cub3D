#include "../../includes/cub3d.h"

static int	check_map_elements(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	data->player.dir = '0'; // not found yet
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			j = skip_spaces(map_tab, i, j);
			if (!map_tab[i][j])
				break ;
			if (!(ft_strchr("10NSEW", map_tab[i][j])))
				return (err_msg(data->mapinfo.path, ERR_INV_CHARACTER,
						FAILURE));
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir != '0')
				return (err_msg(data->mapinfo.path, ERR_NUM_PLAYER, FAILURE));
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir == '0')
				data->player.dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

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
	if (check_map_elements(data, map_tab) == FAILURE)
		return (FAILURE);
	// if (check_player_position(data, map_tab) == FAILURE)
	// 	return (FAILURE);
	if (check_map_is_last(&data->mapinfo) == FAILURE)
		return (err_msg(data->mapinfo.path, ERR_MAP_LAST, FAILURE));
	return (SUCCESS);
}
