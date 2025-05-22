NAME	= minishell

MAIN	= src/hash.c

TEST	= src/tests/test.c

SRC		= src/token/token_list.c \
		src/token/token_type.c \
		src/token/operations.c \
		src/lexer/tokenizer.c \
		src/expander/expander.c \
		src/expander/word_splitting.c \
		src/expander/string_expansion.c \
		src/merger/join_tokens.c \
		src/parser/parser.c \
		src/command/command_list.c \
		src/command/operations.c \
		libs/memory_allocator/aborter.c \
		libs/memory_allocator/allocator.c \
		src/utils/error_handler/error_handler.c \
		src/utils/error_handler/syntax_validate.c \
		src/utils/string_utils/str_classify.c \
		src/utils/string_utils/str_operations.c \
		src/utils/string_utils/str_arr_operations.c \
		src/utils/string_utils/persistent_str_operations.c \
		src/env/env_list.c \
		src/env/operations.c \
		src/signal/signal.c \
		src/builtins/echo.c \
		src/prompt/prompt_string.c \
		src/executor/execute.c \
		src/redirection/heredoc.c \
		src/redirection/redir.c \
		src/redirection/redir_utils.c \
		libs/get_next_line/get_next_line.c \
		src/utils/error_handler/builtin_validate.c \
		src/builtins/export.c \
		src/builtins/env.c \
		src/builtins/pwd.c \
		src/builtins/builtin_utils.c \
		src/builtins/unset.c \
		src/builtins/cd.c \
		src/builtins/exit.c \
		src/executor/execute_utils.c \
		src/executor/find_command.c \

CC = clang
CFLAGS = -g -Wall -Wextra -I./includes -I./libs/libft  -I./libs -I./includes #-fsanitize=address  -fno-omit-frame-pointer  #-Werror
LIBFT = libs/libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(MAIN) $(OBJ) -o $(NAME) $(LIBFT) -lreadline

$(LIBFT):
	make -C libs/libft

test: fclean $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(TEST) $(OBJ) -o $(NAME) $(LIBFT) -lreadline -D DEBUG=1
	make clean

clean:
	rm -f $(OBJ)
	make -C libs/libft clean

fclean: clean
	rm -f $(NAME)
	make -C libs/libft fclean

re: fclean all

.PHONY: all clean fclean re
