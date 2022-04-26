NAME = libft.a
CLIENT = client
SERVER = server
SRCS = Libft/ft_atoi.c Libft/ft_putstr.c Libft/ft_putnbr.c
OBJS = ${SRCS:.c=.o}
FLAGS = -Wall -Wextra -Werror

all: ${CLIENT} ${SERVER}

${SERVER}:
	gcc ${FLAGS} -o server server.c Libft/*.c

${CLIENT}:
	gcc ${FLAGS} -o client client.c Libft/*.c

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME} ${SERVER} ${CLIENT}

re: fclean all

.PHONY: all clean fclean re