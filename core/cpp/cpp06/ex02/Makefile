SRC = main.cpp Identify.cpp\

NAME = Identify

${NAME}: ${SRC}
	g++ -Wall -Wextra -Werror -std=c++98 ${SRC} -o ${NAME}

all: ${NAME}

clean:
	rm -rf ${NAME}

fclean: clean

re: fclean all

.PHONY: all
