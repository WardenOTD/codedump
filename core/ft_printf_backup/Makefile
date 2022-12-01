# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 16:35:10 by jteoh             #+#    #+#              #
#    Updated: 2022/12/01 15:55:49 by jteoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c ft_create.c ft_create2.c ft_create3.c \
			ft_width_flags.c ft_extract.c ft_findspc.c \

OBJS		= $(SRC:.c=.o)

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

NAME		= libftprintf.a

all:	${NAME}

$(NAME): $(OBJS)
	make all -C libft/
	make bonus -C libft/
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	make clean -C libft/

fclean:	clean
	$(RM) $(NAME)
	make fclean -C libft/

re:	fclean $(NAME)
