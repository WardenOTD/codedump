SRC = mymain.cpp\

TEST = main.cpp\

NAME = Array

${NAME}: ${SRC} ${TEST}
	g++ -Wall -Wextra -Werror -std=c++98 ${SRC} -o ${NAME}

test: ${TEST}
	g++ -Wall -Wextra -Werror -std=c++98 ${TEST} -o ${NAME}

all: ${NAME}

clean:
	rm -rf ${NAME}

fclean: clean

re: fclean all

.PHONY: all
