NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_atoi.c \
		ft_itoa.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_memset.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strdup.c \
		ft_strndup.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_split.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_strnstr.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		my_atol.c \
		my_atol_base.c \
		my_ltoa.c \
		my_ltoa_base.c \
		my_strlen.c \
		my_strlen_sep.c \
		my_strlcpy.c \
		my_strdup.c \
		my_strndup.c \
		my_strjoin.c \
		my_count_words.c \
		my_strarr.c \
		my_slice.c \
		my_error.c
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
INCLUDES = -I includes

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
