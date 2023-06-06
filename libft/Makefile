# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dvan-kle <dvan-kle@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/17 18:02:14 by dvan-kle      #+#    #+#                  #
#    Updated: 2023/05/27 13:49:31 by dvan-kle      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

C=gcc

NAME=libft.a

CFLAGS=-Wall -Werror -Wextra

SRC=	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c
		

OBJ=	${SRC:.c=.o} 

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