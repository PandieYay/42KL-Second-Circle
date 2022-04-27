NAME = so_long
SRCS = Libft/ft_putnbr.c
OBJS = ${SRCS:.c=.o}
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): main.c Libft/*.c ${SRCS}
	gcc ${FLAGS} -o so_long main.c Libft/*.c -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re