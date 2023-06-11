# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: danielvankleef <danielvankleef@student.      +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/26 14:40:46 by dvan-kle      #+#    #+#                  #
#    Updated: 2023/06/11 17:02:08 by danielvankl   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

C=gcc

NAME=ft_printf.a

CFLAGS=-Wall -Werror -Wextra

SRC=	ft_printf.c \
		ft_printf_utils.c \
		ft_hexa.c 

OBJ=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(C) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re