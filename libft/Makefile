# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 16:20:05 by arendon-          #+#    #+#              #
#    Updated: 2022/02/07 17:43:18 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

CFLAGS = -Wall -Werror -Wextra

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_minimum_sizet.c ft_maximum_sizet.c ft_putnstr_fd.c \
ft_freearray.c ft_strtrim_ver2.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_atof.c

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRC)
	ar -crs $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
