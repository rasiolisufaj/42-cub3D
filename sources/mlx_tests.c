#include "../includes/cub3d.h"
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

// This structure will be filled with memory addreses from mlx_get_data_addr function
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

int	print_message(t_data *data)
{
	(void)data;
	printf("KEY JUST RELEASED\n");
	return (0);
}

// Handle destroy events
int	handle_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	main(void)
{
	t_data	data;
	int		i;
	int		j;
	int		z;
	int		g;

	data.mlx = mlx_init();
	if (!data.mlx)
	{
		perror(ERR_MLX_START);
		return (1);
	}
	data.mlx_win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "MAIN TEST");
	if (!data.mlx_win)
	{
		perror(ERR_MLX_WIN);
		return (1);
	}
	data.img.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data.img.img)
	{
		perror(ERR_MLX_IMG);
		return (1);
	}
	/*
	** After creating an image, we can call 'mlx_get_data_addr', we pass
	** 'bits_per_pixel', 'size_line', 'endian' by reference. These will then
	** be set accordingly for the *current* data address.
	*/
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
			&data.img.size_line, &data.img.endian);
	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		z = WIN_HEIGHT / 2;
		g = z / 2;
		while (j < WIN_HEIGHT / 2)
		{
			ft_mlx_pixel_put(&data.img, i, j, 0x00FF0000);
			j++;
		}
		while (g < z)
		{
			ft_mlx_pixel_put(&data.img, i, g, 0x0000FF00);
			g++;
		}
		while (z < WIN_HEIGHT)
		{
			ft_mlx_pixel_put(&data.img, i, z, 0x000000FF);
			z++;
		}
		i++;
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
	mlx_hook(data.mlx_win, ON_KEYDOWN, 1L << 0, ft_close, &data);
	mlx_hook(data.mlx_win, ON_DESTROY, 0, handle_destroy, &data);
	mlx_hook(data.mlx_win, ON_KEYUP, 1L << 1, print_message, &data);
	mlx_loop(data.mlx);
}
