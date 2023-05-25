SRC			= push_swap.c detection.c modify_atoi.c utils.c \
				sort.c small_sort.c \
				swap.c push.c rotate.c reverse.c \

BNS			= bonus/*.c \

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.
FSANITIZE	= -fsanitize=address -g
DSYM		= rm -rf *.dSYM

LIBFT		= libft.a
GNL			= bonus/gnl/*.c
BONUS		= checker
NAME		= push_swap

all:	${NAME}

${NAME}: ${LIBFT} ${SRC}
	${CC} ${CFLAGS} ${FSANITIZE} ${SRC} ${LIBFT} -o ${NAME} && ${DSYM}

${LIBFT}:
	make all -C libft/
	mv libft/libft.a .

bonus: ${BNS}
	${CC} ${CFLAGS} ${FSANITIZE} ${BNS} ${GNL} ${LIBFT} -o ${BONUS} && ${DSYM}

clean:
	${RM} *.o
	make clean -C libft/

fclean: clean
	${RM} $(NAME) ${BONUS} ${LIBFT}
	make fclean -C libft/

re:	fclean all bonus

.PHONY: all bonus
