# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/21 08:20:34 by mdilapi           #+#    #+#              #
#    Updated: 2018/05/21 08:20:35 by mdilapi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =	$(wildcard *.c)
OBJ =	$(SRC:.c=.o)
FLAGS = -Wall \
		-Wextra \
		-Werror \

all: $(NAME)

$(NAME): $(OBJ) 
	ar rcs $(NAME) *.o
	ranlib $(NAME)

$(OBJ): $(SRC)
	gcc $(FLAGS) -c libft.h $(SRC)

clean:
	rm $(OBJ)

fclean:
	rm $(NAME)

re: fclean clean all
