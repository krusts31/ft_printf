NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
HEADER = ft_printf.h
LIB = -L libft/ -lft

SRC = ft_printf.c ft_do_char.c ft_do_helx.c ft_do_hex.c ft_do_ptr.c ft_do_str.c ft_do_uni.c

SRC_OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	ar rcs $@ $^

%.o:%.c
	$(CC) -c $(CFLAGS) -o $@ $<

do:
	gcc -o a.out $(SRC) $(LIB) -g

clean:
	/bin/rm -f $(SRC_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
