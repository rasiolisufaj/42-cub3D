/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:46:05 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/11 13:36:32 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	move_forward(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->player.pos_x + data->player.dir_x * MOVE_SPEED;
	ny = data->player.pos_y + data->player.dir_y * MOVE_SPEED;
	return (validate_move(data, nx, ny));
}

static int	move_backward(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->player.pos_x - data->player.dir_x * MOVE_SPEED;
	ny = data->player.pos_y - data->player.dir_y * MOVE_SPEED;
	return (validate_move(data, nx, ny));
}

static int	move_left(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->player.pos_x + data->player.dir_y * MOVE_SPEED;
	ny = data->player.pos_y - data->player.dir_x * MOVE_SPEED;
	return (validate_move(data, nx, ny));
}

static int	move_right(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->player.pos_x - data->player.dir_y * MOVE_SPEED;
	ny = data->player.pos_y + data->player.dir_x * MOVE_SPEED;
	return (validate_move(data, nx, ny));
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1)
		moved += move_forward(data);
	if (data->player.move_y == -1)
		moved += move_backward(data);
	if (data->player.move_x == 1)
		moved += move_right(data);
	if (data->player.move_x == -1)
		moved += move_left(data);
	if (data->player.rotate != 0)
		moved += rotate_player(data, data->player.rotate);
	return (moved);
}
