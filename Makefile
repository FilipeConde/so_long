
CC			= cc
CFLAGS		= -g3 -Wextra -Werror -Wall -I.
LIBFT_DIR	= ./lib/libft
LIBFT		= libft.a
LIBMLX_DIR	= ./lib/MLX42
LIBMLX		= libmlx42.a
C_FILES 	= so_long.c

HEADERS 	= so_long.h
TARGETS 	= so_long

all: $(TARGETS)

$(TARGETS): $(C_FILES) $(LIBFT_DIR)/$(LIBFT) libmlx42
	@$(CC) $(CFLAGS) $(C_FILES) -L$(LIBFT_DIR) -lft -o $@

$(LIBFT_DIR)/$(LIBFT):
	@make -C $(LIBFT_DIR)

libmlx42:
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4

clean:
	@make -C $(LIBFT_DIR) clean
	make -C $(LIBMLX_DIR)/build clean

fclean: clean
	@rm -rf $(TARGETS)
	@rm -rf $(LIBMLX_DIR)/build

re: fclean all