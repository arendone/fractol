# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 16:03:57 by arendon-          #+#    #+#              #
#    Updated: 2022/02/08 11:22:45 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

FLAGS = -Wall -Wextra -Werror -Imlx -Ilibft
FT = -Ilibft -Llibft -lft
MLX = -framework OPENGL -framework AppKit -Imlx -Lmlx -lmlx

FT_PATH = ./libft/
MLX_PATH = ./mlx/

OBJ	= $(patsubst %.c, %.o, $(SRCS))

SRCS=	main.c colors.c mandelbrot.c read_arg.c \
		julia.c tree.c utils.c inter_key.c inter_mouse.c

all: $(NAME)

$(NAME): libft/libft.a mlx/libmlx.a $(OBJ)
	$(CC) $(OBJ) ${FT} ${MLX} -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) main.o
	${MAKE} -C ${FT_PATH} clean
	${MAKE} -C ${MLX_PATH} clean

fclean: clean
	rm -f $(NAME)
	${MAKE} -C ${FT_PATH} fclean
	${RM} ./mlx/libmlx.a

re: fclean all

libft/libft.a:
	${MAKE} -C ${FT_PATH}

mlx/libmlx.a:
	${MAKE} -C ${MLX_PATH}

.PHONY: all clean fclean re mlx libft
