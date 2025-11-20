#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define WIN_WIDTH 1080
#define WIN_HEIGHT 900
#define ESC_KEY 65307
// COLORS
#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

/* IMAGE STRUCTURE */
enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_img
{
	void *img;          // the MLX image
	char *addr;         // pointer to the first pixel
	int bits_per_pixel; // how many bits one pixel uses
	int size_line;      // how many bytes per image row
	int endian;         // byte order
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
}			t_data;

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		pxl = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

int	ft_close(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	return (0);
}

int	handle_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}

int	main(void)
{
	t_data	data;
	int		i;
	int		j;

	data.mlx = mlx_init();
	if (!data.mlx)
	{
		perror("MLX INIT: Could not establish connection to graphical system\n");
		return (1);
	}
	data.mlx_win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "MAIN TEST");
	if (!data.mlx_win)
	{
		perror("MLX WIN: Could not create window\n");
		return (1);
	}
	data.img.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data.img.img)
	{
		perror("MLX_NEW_IMAGE: Could not init image\n");
		return (1);
	}
	/*
	** After creating an image, we can call 'mlx_get_data_addr', we pass
	** 'bits_per_pixel', 'size_line', 'endian' by reference. These will then
	** be set accordingly for the *current* data address.
	*/
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.size_line,
			&data.img.endian);
	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT / 2)
		{
			ft_mlx_pixel_put(&data.img, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
	mlx_hook(data.mlx_win, ON_KEYDOWN, 1L << 0, ft_close, &data);
	mlx_hook(data.mlx_win, ON_DESTROY, 0, handle_destroy, &data);
	mlx_loop(data.mlx);
}
