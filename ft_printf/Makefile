CFLAGS = -Wall -Wextra -Werror
SRC =	ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_unputnbr.c ft_address.c ft_lowhex.c ft_upphex.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)
clean :
	rm -fr $(OBJ) 

fclean : clean
	rm -rf $(NAME)

re : fclean all
