NAME	= minishell

MAIN	= src/main.c

TEST	= src/test.c

SRC		= src/token/token_list.c \
		src/token/token_type.c \
		src/lexer/tokenizer.c \
		src/lexer/lexer.c \
		src/lexer/validator.c \
		src/expander/expander.c \
		src/expander/word_splitting.c \
		src/utils/memory_allocator/aborter.c \
		src/utils/memory_allocator/allocator.c \
		src/utils/error_handler/safe_exit.c \
		src/utils/error_handler/syntax_error.c \
		src/utils/string_utils/str_classify.c \
		src/utils/string_utils/str_operations.c \
		src/utils/string_utils/persistent_str_operations.c \
		src/utils/string_utils/str_token.c \
		src/env/env_list.c \
		src/env/operations.c \
		src/signal/signal.c \
		src/inbuild/echo.c

CC = cc
CFLAGS = -g -Wall -Wextra -I./includes -I./libft   #-Werror
LIBFT = libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(MAIN) $(OBJ) -o $(NAME) $(LIBFT) -lreadline

$(LIBFT):
	make -C libft

test: fclean $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(TEST) $(OBJ) -o $(NAME) $(LIBFT) -lreadline -D DEBUG=1
	make clean

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
