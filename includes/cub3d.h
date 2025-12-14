/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 22:26:11 by raisufaj          #+#    #+#             */
/*   Updated: 2025/12/14 23:25:46 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
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
# define MINIMAP_WIDTH 280
# define MINIMAP_HEIGHT 160
# define MINIMAP_BORDER 5
# define MINIMAP_COLOR 0x00FFFFFF
# define PLAYER_COLOR 0x00FF0000

# ifndef BONUS
#  define BONUS 0
# endif

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define MOVE_SPEED 0.0125
# define ROT_SPEED 0.015

enum			e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	ERR = 2,
	BREAK = 3,
	CONTINUE = 4
};

enum			e_tex_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

// STRUCTURES

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_draw_square
{
	int			x;
	int			y;
	int			size;
	int			color;
}				t_draw_square;

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

typedef struct s_player
{
	char		dir;
	int			move_x;
	int			move_y;
	int			rotate;
	int			has_moved;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

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
	double		x;
	double		y;
	t_mapinfo	mapinfo;
	t_texinfo	texinfo;
	t_player	player;
	// t_ray		ray;
	t_img		minimap;
}				t_data;

/* ERROR MESSAGES*/

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
# define ERR_MAP_MISSING "Missing map"
# define ERR_MAP_NO_WALLS "Map is not enclosed by walls"
# define ERR_MAP_TOO_SMALL "Map must be at least 3 lines high"
# define ERR_MAP_LAST "Map is not the last element of the file"
# define ERR_INV_CHARACTER "Invalid character in map"
# define ERR_NUM_PLAYER "Map has more than one player"
# define ERR_PLAYER_DIR "Map has no player position (expected N, S, E or W)"
# define ERR_PLAYER_POS "Invalid player position"

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

/* create_map.c */
int				create_map(t_data *data, char **file, int i);

/* check_map_borders.c */
int				skip_spaces(char **map, int i, int j);
int				is_valid_cell(char **map_tab, int row, int col);
int				check_map_borders(t_mapinfo *map, char **map_tab);

/* check_map_validity.c */
int				check_map_validity(t_data *data, char **map_tab);

/* error.c */
int				err_msg(char *detail, char *str, int code);
int				err_msg_val(int detail, char *str, int code);

/* free_data.c */
void			free_tab(void **tab);
int				free_data(t_data *data);

/* exit.c */
int				quit_cub3d(t_data *data);
void			clean_exit(t_data *data, int code);

/* init_data.c */
void			init_data(t_data *data);
void			init_img_clean(t_img *img);

/* init_mlx.c */
void			init_mlx(t_data *data);
void			init_texture_img(t_data *data, t_img *image, char *path);
void			init_img(t_data *data, t_img *image, int width, int height);

/* init_textures.c */
void			init_textures(t_data *data);
void			init_texinfo(t_texinfo *textures);

/* init_mlx.c */
void			init_mlx(t_data *data);
void			init_texture_img(t_data *data, t_img *image, char *path);
void			init_img(t_data *data, t_img *image, int width, int height);

/* parsing_utils.c */
bool			ft_is_space(char c);
int				is_whitespace(char c);
int				wall_contains_map_chars(char *line);
int				longest_map_line_len(t_mapinfo *mapinfo, int index);

/*minimap_image.c*/
int				handle_key(int key_code, t_data *data);
void			draw_square(t_data *data, t_draw_square p);
void			draw_map(t_data *data, int tile_size);
void			init_minimap_image(t_data *data);
void			draw_player(t_data *data, int size);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_draw_square	draw_init(int x, int y, int size, int color);

/*player_rotate.c*/
int				rotate_player(t_data *data, double rotdirection);

/*player_position.c*/
int				validate_move(t_data *data, double new_x, double new_y);

/*player_move.c*/
int				move_player(t_data *data);

/*player_direction.c*/
void			init_player_direction(t_data *data);

/*input_handler.c*/
int				render_minimap(t_data *data);
void			listen_for_event_input(t_data *data);

/*detect wall*/
int				detect_wall(double x, double y, t_data *data);

/* render_utils.c */
int				is_tile_visible(int x, int y, int size);

#endif
