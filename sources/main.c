#include "../includes/cub3d.h"

static int	parse_args(t_data *data, char **av)
{
	if (check_file(av[1], true) == FAILURE)
		return (1);
	parse_data(av[1], data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	if (ac != 2)
		return (err_msg("Usage", ERR_USAGE, 1));
	if (parse_args(&data, av) != SUCCESS)
		return (1);
	int i = 0;
	printf("FROM WHILE LOOP: \n");
	while (data.mapinfo.file[i] != 0)
	{
		printf("%s", data.mapinfo.file[i]);
		i++;
	}
	free_tab((void **)data.mapinfo.file);
	return (0);
}
