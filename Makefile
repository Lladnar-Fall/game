NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c
OBJ = $(SRC:.c=.o)

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

LIBS = -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -I $(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all