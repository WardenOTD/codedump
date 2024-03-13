CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.

all: microshell.c
	${CC} ${CFLAGS} microshell.c -o microshell

mine: microshell2.c
	${CC} ${CFLAGS} microshell2.c -o microshell

clean:
	rm -rf microshell

re: clean all

rem: clean mine
