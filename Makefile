NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	map_check.c \
	map_path.c \
	map.c \
	move.c \
	render.c \
	utils.c 


OBJ = $(SRC:.c=.o)

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

LIBS = -lXext -lX11 -lm

LIBFT = ./libft/libft.a

all: $(MLX) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I $(MLX_DIR) -c $< -o $@

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	@make -C libft/

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(MLX) $(LIBS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)
	@make clean -C libft/

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft/

re: fclean all