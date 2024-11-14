# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timanish <timanish@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 11:06:40 by nisi              #+#    #+#              #
#    Updated: 2024/11/14 19:09:09 by timanish         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = minishell
SRCS = parse.c\
		read_line.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C "ft_printf"
	@make -C "libft"
	$(CC) -o $(NAME) $(OBJS) ft_printf/libftprintf.a libft/libft.a -lreadline

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	@make -C "libft" clean
	@make -C "ft_printf" clean

fclean: clean
	rm -f $(NAME)
	@make -C "libft" fclean
	@make -C "ft_printf" fclean

re: fclean all

.PHONY: all clean fclean re bonus