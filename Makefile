# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabuchwa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/08 10:16:53 by mabuchwa          #+#    #+#              #
#    Updated: 2016/05/09 18:23:30 by mabuchwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fdf

SRC = 	main.c parsing.c tools.c calc.c draw.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) -L./libft -lft -L/usr/local/lib/ \
		-I/usr/local/include -lmlx -framework OpenGL -framework AppKit $(OBJ)

$(OBJ):	$(SRC)
	$(CC) $(CFLAGS) -I ./includes/ -c $(SRC)

all: $(NAME)

clean:
	make clean -C libft/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all
