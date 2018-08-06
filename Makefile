#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylesik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/08 15:07:11 by ylesik            #+#    #+#              #
#    Updated: 2018/04/27 16:19:12 by nnaumenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
CFILES = ft_add.c ft_algor.c ft_counters.c ft_valid.c input.c main.c
OFILES = ft_add.o ft_algor.o ft_counters.o ft_valid.o input.o main.o
HEADER = fillit.h

all: $(NAME)

$(NAME):
	make re -C libft
	gcc -Wall -Wextra -Werror -I $(HEADER) -c $(CFILES)
	gcc -o $(NAME) $(OFILES) libft/libft.a

clean:
	make clean -C libft
	/bin/rm -rf $(OFILES)

fclean: clean
	make fclean -C libft
	/bin/rm -rf $(NAME)
	
re: fclean all
