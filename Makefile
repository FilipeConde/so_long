
CC = cc
CFLAGS = -g3 -Wextra -Werror -Wall -I.
C_FILES = so_long.c

HEADERS = so_long.h
TARGETS = so_long

all: $(TARGETS)

so_long: $(C_FILES) libft/libft.a
	@make -C minilibx-linux
	@$(CC) $(CFLAGS) $^ minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a -Llibft -lft -Llibmlx -Llibmlx_Linux -o $@

libft/libft.a:
	@make -C libft/

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -Lminilibx-linux -lminilibx-linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@make -C libft/ clean

fclean: clean
	@rm -rf $(TARGETS)
	@make -C libft/ fclean

re: fclean all