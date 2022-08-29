# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 16:35:10 by jteoh             #+#    #+#              #
#    Updated: 2022/08/26 15:19:55 by jteoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c \

OBJS		= $(SRC:.c=.0)

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
