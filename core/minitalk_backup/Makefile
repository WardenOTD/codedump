CLIENT		= client

SERVER		= server

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

LIBFT		= libft.a

all:	${SERVER} ${CLIENT}

${SERVER}: ${LIBFT} ${SERVER}.c
	${CC} ${CFLAGS} ${SERVER}.c ${LIBFT} -o ${SERVER}

${CLIENT}: ${LIBFT} ${CLIENT}.c
	${CC} ${CFLAGS} ${CLIENT}.c ${LIBFT} -o ${CLIENT}

${LIBFT}:
	make all -C libft/
	mv libft/libft.a .

cclient:
	${RM} ${CLIENT}

cserver:
	${RM} ${SERVER}

clibfta:
	${RM} ${LIBFT}

clean:
	make clean -C libft/

fclean:	cclient cserver clibfta
	${RM} $(NAME)
	make fclean -C libft/

re:	fclean all

.PHONY: all