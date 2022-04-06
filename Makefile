NAME = so_long
SRC = so_long.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) -Lmlx -lmlx -framework OpenGL -framework AppKit  $(SRC)


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all