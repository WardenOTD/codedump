# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 16:35:10 by jteoh             #+#    #+#              #
#    Updated: 2022/12/09 13:22:00 by jteoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c ft_create.c ft_create2.c ft_create3.c \
			ft_width_flags.c ft_extract.c ft_findspc.c ft_scuffed_realloc.c\

OBJS		= $(SRC:.c=.o)

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

NAME		= libftprintf.a
LNAME		= lftprintf.a

all:	${NAME}

$(NAME): $(OBJS)
	make all -C libft/
	make bonus -C libft/
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) print_testing.o
	make clean -C libft/

fclean:	clean
	$(RM) $(NAME)
	$(RM) test
	make fclean -C libft/

re:	fclean $(NAME)

test: $(NAME)
	gcc	-c print_testing.c
	gcc print_testing.o -L. $(NAME) -o test

test_asan: $(NAME)
	gcc	-c print_testing.c
	gcc print_testing.o -L. $(NAME) -fsanitize=address -o test

retest: fclean test
