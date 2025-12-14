/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:56:48 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/14 21:57:39 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_tile_visible(int x, int y, int size)
{
	if (x < -size || x >= MINIMAP_WIDTH)
		return (0);
	if (y < -size || y >= MINIMAP_HEIGHT)
		return (0);
	return (1);
}
