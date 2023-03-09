# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dvan-kle <dvan-kle@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/09 13:40:03 by dvan-kle      #+#    #+#                  #
#    Updated: 2023/03/09 16:54:51 by dvan-kle      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol

MLX = MLX42/build/libmlx42.a

CC = gcc
CC_FLAGS = -Wall -Wextra
MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -lglfw3

SRC = main.c


all: $(NAME)

$(NAME):
	$(CC) $(CC_FLAGS) $(SRC) $(MLX) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(NAME)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all