# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timanish <timanish@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 11:06:40 by nisi              #+#    #+#              #
#    Updated: 2024/11/15 19:43:02 by timanish         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft -I ft_printf
NAME = minishell
SRCS = parce/parse.c\
		parce/read_line.c\

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