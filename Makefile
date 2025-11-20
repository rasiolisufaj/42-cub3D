NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

SRC = sources/main.c
OBJ = $(SRC:.c=.o)

all = $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all