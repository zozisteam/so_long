NAME = libft.a

SRCS = ft_isdigit.c ft_memset.c ft_isprint.c ft_itoa.c ft_strtrim.c \
         ft_strlcat.c ft_substr.c ft_putchar_fd.c ft_atoi.c \
         ft_tolower.c ft_bzero.c ft_putendl_fd.c ft_strlcpy.c \
        ft_putnbr_fd.c ft_calloc.c ft_strlen.c ft_toupper.c ft_memchr.c \
        ft_putstr_fd.c ft_isalnum.c ft_memcmp.c ft_strmapi.c ft_split.c \
        ft_strncmp.c ft_memcpy.c ft_isalpha.c ft_strchr.c ft_strnstr.c \
        ft_isascii.c ft_strdup.c ft_strrchr.c ft_memmove.c ft_strjoin.c \
        ft_striteri.c ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c \
		ft_putnbru.c ft_hexconv.c

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
