NAME = push_swap
CHECKER = checker
LIBFT = Libft/ft_strncmp.c Libft/ft_strcmp.c Libft/ft_atoi.c Libft/ft_atoichecker.c Libft/ft_split.c
SRCS = ./main.c ./arg_checker.c instructions/instructions.c instructions/rotate.c instructions/revrotate.c \
./quicksortalgo.c ./findmedian.c ./insertionsort.c ./partitionisthree.c ./partitionisthreeb.c ./issorted.c ./sortmedian.c
BONUS_SRCS = bonus_checker/main.c bonus_checker/get_next_line_bonus.c bonus_checker/get_next_line_utils_bonus.c \
./arg_checker.c ./issorted.c bonus_checker/instructions/instructions.c bonus_checker/instructions/revrotate.c \
bonus_checker/instructions/rotate.c
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ${SRCS} ${LIBFT}
	gcc ${FLAGS} -o ${NAME} ${SRCS} ${LIBFT}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME} ${CHECKER}

re: fclean all

bonus: $(CHECKER)

$(CHECKER): ${BONUS_SRCS} ${LIBFT}
	gcc ${FLAGS} -o ${CHECKER} ${BONUS_SRCS} ${LIBFT}

.PHONY: all clean fclean re bonus