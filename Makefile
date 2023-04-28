CFLAGS = -Wall -Wextra -Werror
SRC = check_map_utils.c put.c moves.c actions.c check_path.c fill_window.c main.c check_map.c  gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ = $(SRC:%c=%o)
NAME = so_long
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Making done ✅"

$(LIBFT):
	@$(MAKE) -C libft -s >/dev/null

$(PRINTF):
	@$(MAKE) -C ft_printf -s >/dev/null

clean:
	@$(MAKE) -C libft clean -s >/dev/null
	@$(MAKE) -C ft_printf clean -s >/dev/null
	@rm -rf $(OBJ)
	@echo "Cleanning done ✅"

fclean: clean
	@$(MAKE) -C libft fclean -s >/dev/null
	@$(MAKE) -C ft_printf fclean -s >/dev/null
	@rm -rf $(NAME)
	@echo "Fcleaning done ✅"

re: fclean all