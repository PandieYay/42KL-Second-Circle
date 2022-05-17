NAME = push_swap
LIBFT = Libft/ft_strncmp.c Libft/ft_strcmp.c Libft/ft_atoi.c Libft/ft_atoichecker.c Libft/ft_split.c
SRCS = ./main.c ./arg_checker.c instructions/instructions.c instructions/rotate.c instructions/revrotate.c ./quicksortalgo.c ./findmedian.c ./insertionsort.c ./partitionisthree.c ./partitionisthreeb.c
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