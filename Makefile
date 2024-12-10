NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	minishell.c \
		ms_tools.c \
		ms_tokenize.c \
		ms_cmd.c\
		ms_minishell_split.c\
		ms_validate.c\
		ms_expand.c \
		ms_builtins.c
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBX_FLAGS = -lreadline
INCLUDES = -I includes -I $(LIBFT_DIR)/includes -I $(FT_PRINTF_DIR)/includes

all: $(NAME)

debug:
	make -C debug/

$(NAME): $(OBJS) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBX_FLAGS) $(FT_PRINTF) $(LIBFT) -o $@

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
