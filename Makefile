NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

SRC = sources/main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

# Build MiniLibX automatically
$(MLX_LIB):
	@make -C $(MLX_DIR)

# Compile object files
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

# Link everything
$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(OBJ) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib \
		-lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	@make clean -C $(MLX_DIR)

re: fclean all