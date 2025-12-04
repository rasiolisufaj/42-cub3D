# Program file name
NAME = cub3D

# Mode
BONUS = 0

# Compiler and compilation flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

# Minilibx
MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

# Sources
SRC_PATH = ./sources/
SRC = 	main.c \
		parsing/check_args.c \
		parsing/check_textures.c \
		parsing/fill_color_textures.c \
		parsing/parse_file_data.c \
		parsing/get_file_data.c \
		parsing/create_map.c \
		parsing/check_map_borders.c \
		parsing/check_map_validity.c \
		parsing/parsing_utils.c \
		init/init_data.c \
		init/init_textures.c\
		exit/exit.c \
		exit/free_data.c \
		error.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH = ./objects/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

# Includes
INC =	-I ./includes/\
		-I ./libft/\
		-I ./minilibx-linux/

# Main rule
all: $(OBJ_PATH) $(MLX) $(LIBFT) $(NAME)

# Objects directory rule
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)/exit
	mkdir -p $(OBJ_PATH)/init
	mkdir -p $(OBJ_PATH)/debug
	mkdir -p $(OBJ_PATH)/movement
	mkdir -p $(OBJ_PATH)/parsing
	mkdir -p $(OBJ_PATH)/render

# Objects rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -DBONUS=$(BONUS) -c $< -o $@ $(INC)

# Project file rule
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJS) -o $@ $(INC) $(LIBFT) $(MLX) -lXext -lX11 -lm

# Libft rule
$(LIBFT):
	make -sC $(LIBFT_PATH)

# MLX rule
$(MLX):
	make -sC $(MLX_PATH)

bonus:
	make all BONUS=1

# Clean up build files rule
clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

# Removee program executable
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

# Clean + remove executable
re: fclean all

.PHONY: all re clean fclean bonus