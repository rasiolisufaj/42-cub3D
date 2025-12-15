#include "cub3d.h"

void	render_images(t_data *data)
{
	if (BONUS)
		render_minimap(data);
}

int	render(t_data *data)
{
	data->player.has_moved += move_player(data);
	if (data->player.has_moved == 0)
		return (0);
	render_images(data);
	return (0);
}
