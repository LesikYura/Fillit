# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnaumenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/20 12:25:41 by nnaumenk          #+#    #+#              #
#    Updated: 2018/04/05 11:54:24 by nnaumenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.h *.c

OBJECT = *.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
				gcc $(FLAGS) -c -I $(SRC)
				ar rc $(NAME) $(OBJECT)

clean:
				/bin/rm -f $(OBJECT)

fclean: clean
						/bin/rm -f $(NAME)

re: fclean all
