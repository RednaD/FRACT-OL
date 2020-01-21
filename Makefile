# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arusso <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 15:27:09 by arusso            #+#    #+#              #
#    Updated: 2018/10/16 15:28:16 by arusso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS =  -Wall -Werror -Wextra
MLXFLAGS = -framework OpenGL -framework AppKit -lpthread -D_REENTRANT

SRC_PATH = ./srcs/
SRC_NAME = main.c draw.c keys.c
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

INCLUDES_PATH = ./includes/
INCLUDES_NAME = fractol.h
INCLUDES = $(addprefix $(INCLUDES_PATH), $(INCLUDES_NAME))

HEADER_PATH = ./libft/
HEADER_NAME = libft.a
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))

LIBRARY_PATH = ./mlx/
LIBRARY_NAME = libmlx.a
LIBRARY = $(addprefix $(LIBRARY_PATH), $(LIBRARY_NAME))

OBJ = @$(SRC_NAME:.c=.o)

.PHONY : all, clean, fclean, re

all : $(NAME)

$(NAME) :
	@make -C libft
	@make -C mlx
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(SRC) $(HEADER) $(LIBRARY) -o $(NAME)

clean :
	@make clean -C libft
	@make clean -C mlx
	@rm -f $(OBJ)

fclean : clean
	@make fclean -C libft
	@rm -f $(NAME)

re : fclean all
