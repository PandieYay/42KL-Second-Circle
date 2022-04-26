NAME = libft.a
CLIENT = client
SERVER = server
SRCS = Libft/ft_atoi.c Libft/ft_putstr.c
OBJS = ${SRCS:.c=.o}
FLAGS = -Wall -Wextra -Werror

all:
	gcc ${FLAGS} -o server server.c Libft/*.c
	gcc ${FLAGS} -o client client.c Libft/*.c

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${SERVER} ${CLIENT}

re: fclean all