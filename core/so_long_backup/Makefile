SRC			= so_long.c parsing.c validation.c floodfill.c \
				mlx_stuff.c mlx_image_creation.c mlx_movement_admin.c mlx_gameplay.c \
				put_to_term.c \
				get_next_line.c get_next_line_utils.c \

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.
MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit
FSANITIZE	= -fsanitize=address -g
DSYM		= rm -rf *.dSYM

NAME		= so_long

all:	${NAME}

${NAME}: ${SRC}
	${CC} ${CFLAGS} ${MLXFLAGS} ${FSANITIZE} ${SRC} -o ${NAME} && ${DSYM}

clean:
	${RM} *.o

fclean: clean
	${RM} $(NAME)

re:	fclean all

.PHONY: all
