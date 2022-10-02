NAME=so_long
CFLAGS = -Wall -Werror -Wextra -I./minilibx -g
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
MLX = ./minilibx/libmlx.a
LIBFT =	ft_printf/libftprintf.a
GNL_SRCS = ./gnl/get_next_line.c  ./gnl/get_next_line_utils.c
SRCS = main.c data.c map.c window.c player.c move.c utils.c collect.c check_map.c valid_path.c find.c

all : $(MLX) $(NAME)

$(NAME): $(SRCS) $(MLX) $(LIBFT) $(GNL_SRCS)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(LIBFT) $(GNL_SRCS) -o $(NAME)

$(MLX):
	@make -C ./minilibx

$(LIBFT):
	@make bonus -C ./ft_printf


clean:

fclean: clean
	@rm -rf $(NAME)
	@make clean -C ./minilibx
	@make fclean -C ./ft_printf

re : fclean all

.PHONY: clean fclean re