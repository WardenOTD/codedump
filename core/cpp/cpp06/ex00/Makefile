SRC = main.cpp ScalarConverter.cpp\

NAME = ScalarConverter

${NAME}: ${SRC}
	g++ -Wall -Wextra -Werror -std=c++98 ${SRC} -o ${NAME}

all: ${NAME}

clean:
	rm -rf ${NAME}

fclean: clean

re: fclean all

.PHONY: all
