#include "../includes/cub3d.h"

int	err_msg(char *detail, char *str, int code)
{
	ft_putstr_fd("Error", 2);
	if (detail)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(detail, 2);
	}
	if (str)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n", 2);
	return (code);
}

int	err_msg_val(char *detail, char *str, int code)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(detail, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (code);
}
