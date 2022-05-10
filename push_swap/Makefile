NAME = push_swap
LIBFT = Libft/ft_strncmp.c Libft/ft_strcmp.c Libft/ft_atoi.c
SRCS = ./main.c ./arg_checker.c ./instructions.c ./rotinstructions.c ./revrotinstructions.c
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ${SRCS} ${LIBFT}
	gcc ${FLAGS} -o ${NAME} ${SRCS} ${LIBFT}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re