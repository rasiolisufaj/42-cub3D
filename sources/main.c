#include "../includes/cub3d.h"

static int	get_number_of_lines(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		err_msg(path, strerror(errno), errno);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	printf("LINE COUNT: %d\n", line_count);
	return (line_count);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (err_msg("Usage", ERR_USAGE, 1));
	if (check_file(av[1], true) != 0)
		return (1);
	get_number_of_lines(av[1]);
	return (0);
}
