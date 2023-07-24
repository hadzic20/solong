NAME	= so_long

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRCS 	= input_control.c instantiate_objects.c main.c read_map.c validate.c

OBJS	= $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
		make -C ./libs/mlx
		mv ./libs/mlx/libmlx.a ./libmlx.a

		make -C ./libs/Libft
		mv ./libs/Libft/libft.a ./libft.a

		make -C ./libs/ft_printf
		mv ./libs/ft_printf/libftprintf.a ./libftprintf.a
		$(CC) $(CFLAGS) $(SRCS) -framework OpenGL -framework AppKit libmlx.a libft.a libftprintf.a -o $(NAME)

all: 	$(NAME)

clean:
		make -C ./libs/Libft clean
		make -C ./libs/ft_printf clean
		rm -rf */*.o

fclean: clean
		rm -rf libft.a
		rm -rf libftprintf.a
		rm -rf so_long

re: 	fclean all

.PHONY: all clean fclean re
