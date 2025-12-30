
CC			= cc
CFLAGS		= -g3 -Wextra -Werror -Wall -I.
LIBFT_DIR	= ./lib/libft
LIBFT		= libft.a
LIBMLX		= ./lib/MLX42
C_FILES 	= so_long.c

HEADERS 	= so_long.h
TARGETS 	= so_long

all: $(TARGETS)

$(TARGETS): $(C_FILES) $(LIBFT_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) $(C_FILES) -L$(LIBFT_DIR) -lft -o $@

$(LIBFT_DIR)/$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(TARGETS)
	@make -C $(LIBFT_DIR) fclean

re: fclean all