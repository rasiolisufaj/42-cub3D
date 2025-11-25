#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define WIN_WIDTH 960
# define WIN_HEIGHT 720

// ERROR MESSAGES
# define ERR_USAGE "./cub3D <path/to/map.cub>"
# define ERR_FILE_NOT_CUB "Not an acceptable .cub file"
# define ERR_FILE_NOT_XPM "Not a .xpm file"
# define ERR_FILE_IS_DIR "Is a directory"
# define ERR_CUB_NOT_EXIST ".cub file does not exist"
# define ERR_MALLOC "Could not allocate memory"
# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"
# define ERR_MLX_IMG "Could not create mlx image"

/* check_args.c */
int	check_file(char *arg, bool cub);

/* error.c */
int	err_msg(char *detail, char *str, int code);
int	err_msg_val(char *detail, char *str, int code);

#endif