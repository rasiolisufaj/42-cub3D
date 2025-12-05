/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:27:11 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/05 22:27:15 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	skip_spaces(char **map, int i, int j)
{
	while (ft_is_space(map[i][j]) || map[i][j] == '\r' || map[i][j] == '\v'
		|| map[i][j] == '\f')
		j++;
	return (j);
}

int	is_invalid_cell(char **map_tab, int row, int col)
{
	if (row < 0 || col < 0)
		return (FAILURE);
	if (!map_tab[row] || (int)ft_strlen(map_tab[row]) <= col)
		return (FAILURE);
	if (is_whitespace(map_tab[row][col]) == SUCCESS)
		return (FAILURE);
	return (SUCCESS);
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
