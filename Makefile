NAME = minishell
SRC = src/main.c \
src/lexer/token_list.c \
src/lexer/tokenizer.c \
src/lexer/token_type.c \
src/utils/memory-allocator/aborter.c \
src/utils/memory-allocator/allocator.c \
src/utils/safe_exit.c \
src/utils/string_utils/str_classify.c \
src/utils/string_utils/str_operations.c \
src/utils/string_utils/str_operations.c \
src/env/aborter.c \
src/env/allocator \
src/env/operations.c



CC = cc
CFLAGS = -g -Wall -Wextra -I./includes -I./libft   #-Werror
LIBFT = libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) -lreadline

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
