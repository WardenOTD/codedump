SRC			= philo.c creation.c thread_stuff.c util.c util2.c \


CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -I.
FSANITIZE	= -fsanitize=thread -g3
DSYM		= *.dSYM

NAME		= philo

all: ${NAME}

${NAME}: ${SRC}
	${CC} ${CFLAGS} ${FSANITIZE} ${SRC} -o ${NAME} && ${RM} ${DSYM}

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all
