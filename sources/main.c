#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (err_msg("Usage", ERR_USAGE, 1));
	check_file(av[1], true);
	return (0);
}