CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

test1:
	${CC} ${CFLAGS} megaphone.cpp -o megaphone
	./megaphone "shhhhh... I think the students are asleep..."

test2:
	${CC} ${CFLAGS} megaphone.cpp -o megaphone
	./megaphone Damnit " ! " "Sorry students, I thought this thing was off."

test3:
	${CC} ${CFLAGS} megaphone.cpp -o megaphone
	./megaphone

test4:
	${CC} ${CFLAGS} megaphone.cpp -o megaphone

clean:
	rm -rf megaphone
