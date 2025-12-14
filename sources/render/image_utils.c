/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:51:15 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/14 20:51:27 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 280 || y < 0 || y >= 160)
		return ;
	dst = (char *)data->minimap.addr + (y * data->minimap.size_line + x
			* (data->minimap.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
