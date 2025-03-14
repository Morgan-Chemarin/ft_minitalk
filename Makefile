# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dev <dev@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 00:41:49 by dev               #+#    #+#              #
#    Updated: 2025/03/14 00:41:51 by dev              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

CC = gcc
CFLAGS = -Werror -Wextra -Werror

SRC_CLIENT = src/client.c src/utils.c ft_printf/ft_printf.c \
			ft_printf/ft_putchar_pf.c ft_printf/ft_putnbr_pf.c ft_printf/ft_putstr_pf.c \
			ft_printf/ft_puthex_pf.c
SRC_SERVER = src/server.c src/utils.c ft_printf/ft_printf.c \
			ft_printf/ft_putchar_pf.c ft_printf/ft_putnbr_pf.c ft_printf/ft_putstr_pf.c \
			ft_printf/ft_puthex_pf.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER)

%.o: %.c includes/minitalk.h ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re