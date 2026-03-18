SRC = recaman.c
SRCASM = recaman.s

NAME = recaman
NAMEASM = recamanasm

all: $(NAME)

$(NAME): $(SRC) $(SRCASM)
	gcc -o $(NAME) $(SRC)
	nasm -f elf64 $(SRCASM) -o recaman.o
	gcc -o $(NAMEASM) recaman.o

run: $(NAME) $(NAMEASM)
	./$(NAME)
	./$(NAMEASM)

clean:
	rm -f $(NAME) $(NAMEASM) recaman.o
