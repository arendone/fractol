# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 16:03:57 by arendon-          #+#    #+#              #
#    Updated: 2022/02/03 17:12:19 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ	= $(patsubst %.c, %.o, $(SRCS))

SRCS=	main.c colors.c mandelbrot.c read_arg.c \
		julia.c tree.c utils.c inter_key.c inter_mouse.c

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	$(CC) $(OBJ) -Llibft -lft -L ./mlx/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -Ilibft -c $< -o $@

clean:
	rm -f $(OBJ) main.o
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean $(NAME)

libft/libft.a:
	make -C libft all

.PHONY: all, clean, fclean, re
