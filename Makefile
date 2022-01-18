# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 16:48:58 by yalthaus          #+#    #+#              #
#    Updated: 2022/01/18 17:09:11 by yalthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC	=	push_swap.c\
		utils.c\
		utils2.c\
		ps_move1.c\
		ps_move2.c\
		ps_move3.c\

OBJ =	$(SRC:.c=.o)

CC =	gcc
RM =	rm -f

CFLAGS =	-Wall -Werror -Wextra

all:	$(NAME)

$(NAME): ${OBJ}
	$(CC) $(CFLAGS) -g -o $(NAME) ${OBJ}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all bonus clean fclean re
