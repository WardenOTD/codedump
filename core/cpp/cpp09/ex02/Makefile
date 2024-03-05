SRC = main.cpp PmergeMe.cpp\

NAME = PmergeMe

${NAME}: ${SRC}
	g++ -Wall -Wextra -Werror -std=c++98 ${SRC} -o ${NAME}

all: ${NAME}

clean:
	rm -rf ${NAME}

fclean: clean

re: fclean all

.PHONY: all