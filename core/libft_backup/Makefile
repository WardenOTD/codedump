# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 10:34:49 by jteoh             #+#    #+#              #
#    Updated: 2022/07/05 17:28:37 by jteoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FUNC	= ft_isalnum.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
			ft_isalpha.c ft_strncmp.c ft_memchr.c \
			ft_memcpy.c ft_memcmp.c \
			ft_bzero.c ft_isascii.c \
			ft_memmove.c ft_strlen.c \
			ft_isdigit.c ft_memset.c ft_isprint.c \

OBJS	= $(FUNC:.c=.o)


CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I.

NAME	= libft.a

all:	${NAME}

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean $(NAME)

