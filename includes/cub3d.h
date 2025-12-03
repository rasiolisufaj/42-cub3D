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
# define TEX_SIZE 64

enum			e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	ERR = 2,
	BREAK = 3,
	CONTINUE = 4
};

// STRUCTURES

typedef struct s_texinfo
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			*floor;
	int			*ceiling;
	int			size;
	int			index;
	double		step;
	double		pos;
	int			x;
	int			y;
}				t_texinfo;

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
}				t_mapinfo;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	char		**map;
	int			**textures;
	int			**texture_pixels;
	t_mapinfo	mapinfo;
	t_texinfo	texinfo;
	// t_player	player;
	// t_ray		ray;
	// t_img		minimap;
}				t_data;

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
# define ERR_TEX_INVALID "Invalid texture(s)"
# define ERR_INVALID_MAP "Map content is wrong or incomplete"
# define ERR_F_C_IDENTIFIER "Invalid floor/ceiling identifier"
# define ERR_CEILING_COLOR "Invalid ceiling RGB color"
# define ERR_FLOOR_COLOR "Invalid floor RGB color"
# define ERR_RGB_VAL " Invalid RGB value (min: 0, max: 255)"
# define ERR_TEX_MISSING "Missing texture(s)"
# define ERR_COLOR_MISSING "Missing RGB color(s)"

/* check_args.c */
int				check_file(char *arg, bool cub);

/* check_textures.c */
int				check_textures_validity(t_data *data, t_texinfo *textures);

/* parse_data.c */
void			parse_data(char *path, t_data *data);

/* get_file_data.c */
int				get_file_data(t_data *data, char **map);

/* create_map.c */
int				create_map(t_data *data, char **file, int i);

/* fill_color_textures.c */
int				fill_color_textures(t_data *data, t_texinfo *texinfo,
					char *line, int j);

/* error.c */
int				err_msg(char *detail, char *str, int code);
int				err_msg_val(int detail, char *str, int code);

/* free_data.c */
int				free_data(t_data *data);

/* exit.c */
void			clean_exit(t_data *data, int code);
int				quit_cub3d(t_data *data);

/* init_data.c */
void			init_data(t_data *data);

/* init_textures.c */
void			init_texinfo(t_texinfo *textures);

/* init_mlx.c */

/* free_data.c */
void			free_tab(void **tab);

/* parsing_utils.c */
bool			ft_is_space(char c);
int				is_whitespace(char c);
int				longest_map_line_len(t_mapinfo *mapinfo, int index);

#endif