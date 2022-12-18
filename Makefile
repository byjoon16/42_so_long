# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byjeon <byjeon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 20:54:10 by byjeon            #+#    #+#              #
#    Updated: 2022/12/14 18:20:07 by byjeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = main.c check.c move.c map.c line.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
FWFLAG = -framework

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -L ./mlx -l mlx $(FWFLAG) OpenGL $(FWFLAG) AppKit -o $(NAME) $^

%.o : %.c
	$(CC) -I ./mlx $(FLAGS) -c $<

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
