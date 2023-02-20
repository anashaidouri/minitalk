# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 23:41:00 by ahaidour          #+#    #+#              #
#    Updated: 2023/02/20 22:58:38 by ahaidour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_cli = client
NAME_serv = server
NAME_cli_B = client_bonus
NAME_serv_B = server_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = client.c libft/ft_atoi.c ft_printf/handle_conversion.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putnbr_hex.c\
	ft_printf/ft_putnbr_unsigned.c ft_printf/ft_putstr.c ft_printf/ft_printf.c ft_printf/ft_strlen.c
SRC_s = server.c libft/ft_atoi.c ft_printf/handle_conversion.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putnbr_hex.c\
	ft_printf/ft_putnbr_unsigned.c ft_printf/ft_putstr.c ft_printf/ft_printf.c ft_printf/ft_strlen.c

SRC_B = bonus/client_bonus.c libft/ft_atoi.c ft_printf/handle_conversion.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putnbr_hex.c\
	ft_printf/ft_putnbr_unsigned.c ft_printf/ft_putstr.c ft_printf/ft_printf.c ft_printf/ft_strlen.c
SRC_s_B = bonus/server_bonus.c libft/ft_atoi.c ft_printf/handle_conversion.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putnbr_hex.c\
	ft_printf/ft_putnbr_unsigned.c ft_printf/ft_putstr.c ft_printf/ft_printf.c ft_printf/ft_strlen.c

OBJ_cli = $(SRC:.c=.o)
OBJ_serv = $(SRC_s:.c=.o)

OBJ_cli_B = $(SRC_B:.c=.o)
OBJ_serv_B = $(SRC_s_B:.c=.o)

all: $(NAME_cli) $(NAME_serv)

bonus: $(NAME_cli_B) $(NAME_serv_B)

$(NAME_serv): $(OBJ_serv)
	$(CC) $(CFLAGS) $(OBJ_serv) -o server
$(NAME_cli): $(OBJ_cli)
	$(CC) $(CFLAGS) $(OBJ_cli) -o client

$(NAME_serv_B): $(OBJ_serv_B)
	$(CC) $(CFLAGS) $(OBJ_serv_B) -o server_bonus
$(NAME_cli_B): $(OBJ_cli_B)
	$(CC) $(CFLAGS) $(OBJ_cli_B) -o client_bonus

clean:
	$(RM) $(OBJ_cli)
	$(RM) $(OBJ_serv)
	$(RM) $(OBJ_cli_B)
	$(RM) $(OBJ_serv_B)

fclean: clean
	$(RM) $(NAME_cli)
	$(RM) $(NAME_serv)

	$(RM) $(NAME_cli_B)
	$(RM) $(NAME_serv_B)

re: fclean all bonus
