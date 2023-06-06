# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dvan-kle <dvan-kle@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/20 22:07:37 by dvan-kle      #+#    #+#                  #
#    Updated: 2023/06/06 14:23:03 by dvan-kle      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = libft/libft.a
MLX = MLX42/build/libmlx42.a

CC = gcc
CC_FLAGS = -Wall -Wextra
MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -lglfw3

SRC = src/fractol.c src/colors.c src/mandelbrot.c src/checks.c src/julia.c

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "\033[32mCompile fract-ol\033[0m"
	$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "\033[32mBuild complete\033[0m"

$(OBJ_DIR)%.o: %.c
	@echo "\033[32mCompile Objects\033[0m"
	mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) -c $< -o $@

$(LIBFT):
	@echo "\033[32mBuilding Libft\033[0m"
	$(MAKE) all -C libft

clean:
	@echo "\033[32mRun clean\033[0m"
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C libft

fclean: clean
	@echo "\033[32mRun fclean\033[0m"
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all