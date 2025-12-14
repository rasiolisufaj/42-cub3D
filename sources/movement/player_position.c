/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:41:30 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/14 20:44:19 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	detect_wall(double x, double y, t_data *data)
{
	int	map_x;
	int	map_y;

	if (!data || !data->map)
		return (1);
	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= data->mapinfo.height)
		return (1);
	if (map_x < 0 || map_x >= (int)ft_strlen(data->map[map_y]))
		return (1);
	return (data->map[map_y][map_x] == '1');
}

static bool	is_walkable_tile(t_data *data, double x, double y)
{
	int	mx;
	int	my;

	mx = (int)x;
	my = (int)y;
	if (data->map[my][mx] == '0')
		return (true);
	return (false);
}

static bool	is_inside_map_bounds(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->mapinfo.width - 1.25)
		return (false);
	if (y < 0.25 || y >= data->mapinfo.height - 0.25)
		return (false);
	return (true);
}

static bool	is_valid_position(t_data *data, double x, double y)
{
	if (!BONUS && is_inside_map_bounds(data, x, y))
		return (true);
	if (BONUS && is_walkable_tile(data, x, y))
		return (true);
	return (false);
}

int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_position(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_position(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}
