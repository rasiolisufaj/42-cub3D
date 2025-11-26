#include "../../includes/cub3d.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

// static void	free_map(t_data *data)
// {
// 	if (data->mapinfo.fd > 0)
// 		close(data->mapinfo.fd);
// 	if (data->mapinfo.file)
// 		free_tab((void **)data->mapinfo.file);
// 	if (data->map)
// 		free_tab((void **)data->map);
// }