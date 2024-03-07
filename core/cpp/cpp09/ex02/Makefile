SRC = main.cpp PmergeMe.cpp\

NAME = PmergeMe

${NAME}: ${SRC}
	g++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3 ${SRC} -o ${NAME} && rm -rf *.dSYM

all: ${NAME}

clean:
	rm -rf ${NAME}

fclean: clean

re: fclean all

.PHONY: all