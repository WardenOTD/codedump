SRC			= push_swap.c detection.c modify_atoi.c utils.c \
				sort.c small_sort.c \
				swap.c push.c rotate.c reverse.c \

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.
FSANITIZE	= -fsanitize=address -g
DSYM		= rm -rf *.dSYM

LIBFT		= libft.a
NAME		= push_swap

all:	${NAME}

${NAME}: ${LIBFT} ${SRC}
	${CC} ${CFLAGS} ${FSANITIZE} ${SRC} ${LIBFT} -o ${NAME} && ${DSYM}

${LIBFT}:
	make all -C libft/
	mv libft/libft.a .

clean:
	${RM} *.o
	make clean -C libft/

fclean: clean
	${RM} $(NAME) ${LIBFT}
	make fclean -C libft/

re:	fclean all

.PHONY: all
