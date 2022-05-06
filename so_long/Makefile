NAME = so_long
LIBFT = Libft/ft_itoa.c Libft/ft_putnbr.c Libft/ft_putstr.c Libft/get_next_line_bonus.c Libft/get_next_line_utils_bonus.c
SRCS = ./main.c ./animation.c ./enemy.c ./map_checker.c ./map_generator.c ./player.c ./pointanddestroy.c
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ${SRCS} ${LIBFT}
	gcc ${FLAGS} -o ${NAME} ${SRCS} ${LIBFT} -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re