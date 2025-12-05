#include "../../includes/cub3d.h"

bool	ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (SUCCESS);
	return (FAILURE);
}

int	longest_map_line_len(t_mapinfo *mapinfo, int index)
{
	int		i;
	size_t	max;
	size_t	len;

	max = 0;
	i = index;
	while (mapinfo->file[i])
	{
		len = ft_strlen(mapinfo->file[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

int	wall_contains_map_chars(char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (ft_strchr("01NSEW", line[j]))
			return (1);
		j++;
	}
	return (0);
}
