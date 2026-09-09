# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsomjaip <nsomjaip@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/09 13:50:42 by nsomjaip          #+#    #+#              #
#    Updated: 2026/09/09 13:50:42 by nsomjaip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_print_hex_lower.c ft_print_hex_upper.c \
		ft_print_pointer.c ft_print_unsigned_dec.c \
		ft_printf.c ft_putchar_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_printf.c

OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
