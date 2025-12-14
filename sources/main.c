/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:28:22 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/14 21:54:46 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_args(t_data *data, char **av)
{
	if (check_file(av[1], true) == FAILURE)
		clean_exit(data, FAILURE);
	parse_data(av[1], data);
	if (get_file_data(data, data->mapinfo.file) == FAILURE)
		return (free_data(data));
	if (check_map_validity(data, data->map) == FAILURE)
		return (free_data(data));
	if (check_textures_validity(data, &data->texinfo) == FAILURE)
		return (free_data(data));
	init_player_direction(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (ac != 2)
		return (err_msg("Usage", ERR_USAGE, 1));
	init_data(&data);
	if (parse_args(&data, av) != SUCCESS)
		return (1);
	init_mlx(&data);
	init_textures(&data);
	listen_for_event_input(&data);
	mlx_loop_hook(data.mlx, render_minimap, &data);
	mlx_loop(data.mlx);
	return (0);
}
