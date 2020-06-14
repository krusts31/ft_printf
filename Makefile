NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

LIB = -L/libft -llibft.a

SRC = ft_printf.c

SRC_OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	ar rcs $@ $^

%.o:%.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	/bin/rm -f $(SRC_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
