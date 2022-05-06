NAME = libft.a

SRCS = *.c

SRCO = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(SRCO)
	ar -cr $(NAME) $(SRCO)

$(SRCO): 
	gcc -Wall -Werror -Wextra -c $(SRCS)

clean :
	rm -f $(SRCO)

fclean : clean
	rm -f $(NAME)
	
re : fclean all
