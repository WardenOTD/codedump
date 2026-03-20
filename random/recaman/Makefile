SRC = recaman.c
SRCASM = recaman.s

NAME = recaman
NAMEASM = recamanasm

RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))

all: $(NAME)

$(NAME): $(SRC) $(SRCASM)
	gcc -o $(NAME) $(SRC)
	nasm -f elf64 $(SRCASM) -o recaman.o
	gcc -o $(NAMEASM) recaman.o

re: clean all

run: $(NAME) $(NAMEASM)
	./$(NAME) $(RUN_ARGS)
	./$(NAMEASM)

%:
	@:

clean:
	rm -f $(NAME) $(NAMEASM) recaman.o
