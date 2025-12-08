/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:28:22 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/08 16:31:42 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (check_map_validity(data, data->map) == FAILURE)
		return (free_data(data));
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (err_msg("Usage", ERR_USAGE, 1));
	init_data(&data);
	if (parse_args(&data, av) != SUCCESS)
		return (1);
	init_mlx(&data);
	init_textures(&data);
	free_data(&data);
	mlx_destroy_display(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_image(data.mlx, data.minimap.img);
	// mlx_loop(data.mlx);
	return (0);
}
