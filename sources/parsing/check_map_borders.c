#include "../../includes/cub3d.h"

int	skip_spaces(char **map, int i, int j)
{
	while (ft_is_space(map[i][j]) || map[i][j] == '\r' || map[i][j] == '\v'
		|| map[i][j] == '\f')
		j++;
	return (j);
}

static int	is_full_wall_row(char **map, int row)
{
	int	j;

	if (!map || !map[row] || !map[row][0])
		return (FAILURE);
	j = skip_spaces(map, row, 0);
	while (map[row][j])
	{
		if (map[row][j] != '1')
			return (FAILURE);
		j++;
	}
	return (SUCCESS);
}

static int	check_middle_row_edges(char **map, int row)
{
	int	len;

	len = ft_strlen(map[row]);
	if (len == 0)
		return (FAILURE);
	if (map[row][len - 1] != '1')
		return (FAILURE);
	if (map[row][0] != '1')
		return (FAILURE);
	return (SUCCESS);
}

int	check_map_borders(t_mapinfo *map, char **map_tab)
{
	int	i;

	if (is_full_wall_row(map_tab, 0) == FAILURE)
		return (FAILURE);
	i = 1;
	while (i < map->height - 1)
	{
		if (check_middle_row_edges(map_tab, i) == FAILURE)
			return (FAILURE);
		i++;
	}
	if (is_full_wall_row(map_tab, i) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
