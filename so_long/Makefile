NAME = so_long
SRCS = *.c Libft/*.c
OBJS = ${SRCS:.c=.o}
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ${SRCS}
	gcc ${FLAGS} -o so_long ${SRCS} -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re