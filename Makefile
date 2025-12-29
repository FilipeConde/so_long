
CC = cc
CFLAGS = -g3 -Wextra -Werror -Wall -I.
C_FILES = so_long.c

HEADERS = so_long.h
TARGETS = so_long

all: $(TARGETS)

so_long: $(C_FILES) libft/libft.a
	@$(CC) $(CFLAGS) $^ -Llibft -lft -o $@

libft/libft.a:
	@make -C libft/

clean:
	@make -C libft/ clean

fclean: clean
	@rm -rf $(TARGETS)
	@make -C libft/ fclean

re: fclean all