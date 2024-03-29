# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dvan-kle <dvan-kle@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/20 22:07:37 by dvan-kle      #+#    #+#                  #
#    Updated: 2023/06/14 15:37:05 by dvan-kle      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol


LIBFT = libft/libft.a
FT_PRINTF = ft_printf/ft_printf.a
MLX_DIR = MLX42/
MLX = MLX42/build/libmlx42.a

CC = gcc
CC_FLAGS = -Wall -Wextra
MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -lglfw3
SRC = src/fractol.c src/utils.c src/mandelbrot.c src/checks.c src/julia.c src/hooks.c

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: libmlx $(NAME)

.SILENT:

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@echo "\033[32mCompile fract-ol\033[0m"
	$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "\033[32mBuild complete\033[0m"

$(OBJ_DIR)%.o: %.c
	@echo "\033[32mCompiling Objects\033[0m"
	mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) -c $< -o $@

$(LIBFT):
	@echo "\033[32mBuilding Libft\033[0m"
	$(MAKE) all -C libft

$(FT_PRINTF):
	@echo "\033[32mBuilding Printf\033[0m"
	$(MAKE) all -C ft_printf

libmlx:
	cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

clean:
	@echo "\033[32mRun clean\033[0m"
	rm -rf $(OBJ_DIR)
	rm -rf MLX42/build
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf
	

fclean: clean
	@echo "\033[32mRun fclean\033[0m"
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf

re: fclean all