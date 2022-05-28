NAME = so_long
SRC = ./src/*.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
MLX = ./mlx/libmlx.a
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
	make clean -C libft

re: fclean all