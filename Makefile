NAME = so_long
SRC = so_long.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
MLX = ./mlx/mlx.a
LIBFT = cd libft && make
LIB = libft/libft.a
CC = gcc

$(NAME):
	$(LIBFT)
	make -C ./mlx
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIB) $(MLX) -framework OpenGL -framework AppKit

all: $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C mlx

fclean: clean
	rm -rf $(NAME)
	make clean -C mlx

re: fclean all