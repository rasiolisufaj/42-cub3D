/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:27:25 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/05 22:27:28 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	is_numeric(char *str)
{
	int	i;

	if (!str || !str[0])
		return (false);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static int	*copy_rgb_arr(char **rgb_arr, int *rgb)
{
	int		i;
	char	*clean;

	i = 0;
	while (rgb_arr[i])
	{
		clean = ft_strtrim(rgb_arr[i], " \n\t\r\v\f");
		if (!clean || !is_numeric(clean))
		{
			free(clean);
			free_tab((void **)rgb_arr);
			free(rgb);
			return (NULL);
		}
		rgb[i] = ft_atoi(clean);
		free(clean);
		i++;
	}
	free_tab((void **)rgb_arr);
	return (rgb);
}

static int	*set_rgb_colors(char *str)
{
	char	**rgb_arr;
	int		*rgb;
	int		count;

	rgb_arr = ft_split(str, ',');
	if (!rgb_arr)
		return (NULL);
	count = 0;
	while (rgb_arr[count])
		count++;
	if (count != 3)
	{
		free_tab((void **)rgb_arr);
		return (0);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
		return (err_msg(NULL, ERR_MALLOC, ERR), NULL);
	return (copy_rgb_arr(rgb_arr, rgb));
}

int	fill_color_textures(t_data *data, t_texinfo *texinfo, char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1]))
		return (err_msg(data->mapinfo.path, ERR_F_C_IDENTIFIER, ERR));
	if (line[j] == 'C' && !(texinfo->ceiling))
	{
		texinfo->ceiling = set_rgb_colors(line + j + 1);
		if (texinfo->ceiling == 0)
			return (err_msg(data->mapinfo.path, ERR_CEILING_COLOR, ERR));
	}
	else if (line[j] == 'F' && !(texinfo->floor))
	{
		texinfo->floor = set_rgb_colors(line + j + 1);
		if (texinfo->floor == 0)
			return (err_msg(data->mapinfo.path, ERR_FLOOR_COLOR, ERR));
	}
	else
		return (err_msg(data->mapinfo.path, ERR_F_C_IDENTIFIER, ERR));
	return (SUCCESS);
}
