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

int	biggest_map_line_len(t_mapinfo *mapinfo, int index)
{
	size_t	biggest_len;

	biggest_len = ft_strlen(mapinfo->file[index]);
	while (mapinfo->file[index])
	{
		if (ft_strlen(mapinfo->file[index]) > biggest_len)
			biggest_len = ft_strlen(mapinfo->file[index]);
		index++;
	}
	return (biggest_len);
}
