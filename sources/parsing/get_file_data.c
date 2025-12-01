#include "../../includes/cub3d.h"

static char	*get_texture_path(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	while (line[j] && ft_is_space(line[j]))
		j++;
	len = j;
	while (line[len] && !ft_is_space(line[len]))
		len++;
	path = malloc(sizeof(char) * len - j + 1);
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && !ft_is_space(line[j]) && line[j] != '\n')
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && ft_is_space(line[j]))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

static int	fill_texture_direction(t_texinfo *texture, char *line, int j)
{
	if (line[j + 2] && ft_isprint(line[j + 2]))
		return (ERR);
	if (line[j] == 'N' && line[j + 1] == 'O' && !(texture->north))
		texture->north = get_texture_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(texture->south))
		texture->south = get_texture_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(texture->west))
		texture->west = get_texture_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(texture->east))
		texture->east = get_texture_path(line, j + 2);
	else
		return (ERR);
	return (SUCCESS);
}

static int	filter_info(t_data *data, char **map, int i, int j)
{
	while (ft_is_space(map[i][j]) || map[i][j] == '\n')
		j++;
	if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
	{
		if (map[i][j + 1] && ft_isprint(map[i][j + 1]) && !ft_isdigit(map[i][j
				+ 1]))
		{
			if (fill_texture_direction(&data->texinfo, map[i], j) == ERR)
				return (err_msg(data->mapinfo.path, ERR_TEX_INVALID, FAILURE));
			return (BREAK);
		}
		else
		{
			if (fill_color_textures(data, &data->texinfo, map[i], j) == ERR)
				return (FAILURE);
			return (BREAK);
		}
	}
	else if (ft_isdigit(map[i][j]))
	{
		// if (create_map(data, map, i) == FAILURE)
		// 	return (err_msg(data->mapinfo.path, ERR_INVALID_MAP, FAILURE));
		printf("JEMI TE MAP\n");
		return (SUCCESS);
	}
	return (CONTINUE);
}

int	get_file_data(t_data *data, char **map)
{
	int i;
	int j;
	int retval;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			retval = filter_info(data, map, i, j);
			if (retval == BREAK)
				break ;
			else if (retval == FAILURE)
				return (FAILURE);
			else if (retval == SUCCESS)
				return (SUCCESS);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}