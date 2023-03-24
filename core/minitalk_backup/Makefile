CLIENT		= client

SERVER		= server

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

NAME		= minitalk.a

all:	${NAME} ${SERVER} ${CLIENT}

$(NAME):
	make all -C libft/
	make bonus -C libft/
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) ${CLIENT}.c ${SERVER}.c

${SERVER}:
	${CC} ${CFLAGS} ${SERVER}.c ${NAME} -o ${SERVER}

${CLIENT}:
	${CC} ${CFLAGS} ${CLIENT}.c ${NAME} -o ${CLIENT}

cclient:
	${RM} ${CLIENT}

cserver:
	${RM} ${SERVER}

clean:
	make clean -C libft/

fclean:	clean
	${RM} ${CLIENT} ${SERVER}
	${RM} $(NAME)
	make fclean -C libft/

re:	fclean
	${RM} $(NAME)
	make
