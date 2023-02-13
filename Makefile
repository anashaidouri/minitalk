# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 23:41:00 by ahaidour          #+#    #+#              #
#    Updated: 2023/02/12 23:39:28 by ahaidour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_cli = client
NAME_serv = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = client.c libft/ft_atoi.c ft_printf/handle_conversion.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putnbr_hex.c\
	ft_printf/ft_putnbr_unsigned.c ft_printf/ft_putstr.c ft_printf/ft_printf.c ft_printf/ft_strlen.c
SRC_s = server.c libft/ft_atoi.c ft_printf/handle_conversion.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putnbr_hex.c\
	ft_printf/ft_putnbr_unsigned.c ft_printf/ft_putstr.c ft_printf/ft_printf.c ft_printf/ft_strlen.c

OBJ_cli = $(SRC:.c=.o)
OBJ_serv = $(SRC_s:.c=.o)

all: $(NAME_cli) $(NAME_serv)

$(NAME_serv): $(OBJ_serv)
	$(CC) $(CFLAGS) $(OBJ_serv) -o server
$(NAME_cli): $(OBJ_cli)
	$(CC) $(CFLAGS) $(OBJ_cli) -o client

clean:
	$(RM) $(OBJ_cli)
	$(RM) $(OBJ_serv)

fclean: clean
	$(RM) $(NAME_cli)
	$(RM) $(NAME_serv)

re: fclean all
