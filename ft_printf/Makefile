NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_printf.c \
		ft_chardup.c \
		ft_convert_num.c \
		ft_convert_ptr.c \
		ft_join_format.c \
		ft_write_result.c
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
LIBFT_DIR = ../Libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I includes -I $(LIBFT_DIR)/includes

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar -rc $(NAME) $(OBJS) $(LIBFT)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
