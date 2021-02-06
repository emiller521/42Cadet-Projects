# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elmiller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/04 10:55:07 by elmiller          #+#    #+#              #
#    Updated: 2019/05/04 11:45:13 by elmiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = fillit.c validation.c coordinates.c mapping.c solve.c placement.c
OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME):
	make -C ./libft/ fclean && make -C ./libft/
	$(CC) $(CFLAGS) -I ./libft/ -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS) -L ./libft -lft

clean:
	/bin/rm -rf $(OBJS)
	make clean -C libft

.PHONY: clean

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft

re: fclean all
