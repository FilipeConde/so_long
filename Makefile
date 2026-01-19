
CC			= cc
CFLAGS		= -g3 -Wextra -Werror -Wall -no-pie -I. -Wunreachable-code #-Ofast UNCOMMENT!!!!!!!
LIBFT_DIR	= ./lib/libft
LIBFT		= libft.a
LIBMLX_DIR	= ./lib/MLX42
LIBMLX		= libmlx42.a
C_FILES		= so_long.c \
				src/map/read_map.c \
				src/map/map_checker.c \
				src/map/set_board.c \
				src/map/free_board.c \
				src/map/map_has_entity.c \
				src/map/flood_fill.c \
				src/map/free_map.c \
				src/map/update_p_pos.c \
				src/map/check_extention.c \
				src/graphics/mount_window.c \
				src/graphics/delete_images.c \
				src/graphics/set_sprites.c \
				src/graphics/set_game.c \
				src/graphics/print_board.c \
				src/graphics/key_capture.c \
				src/graphics/do_collect.c \
				src/graphics/do_win.c

LIBS		= $(LIBMLX_DIR)/build/$(LIBMLX) \
				$(LIBFT_DIR)/$(LIBFT) \
				-ldl -lglfw -pthread -lm

HEADERS		= -I . \
				-I $(LIBMLX_DIR)/include/MLX42 \
				-I $(LIBFT_DIR)

TARGETS 	= so_long

all: $(TARGETS)

DEMO: DEMO.c libft libmlx42
	@$(CC) $(CFLAGS) DEMO.c $(HEADERS) $(LIBS) -o $@
	@echo "==> so_long successfully compiled!"

$(TARGETS): $(C_FILES) libft libmlx42
	@$(CC) $(CFLAGS) $(C_FILES) $(HEADERS) $(LIBS) -o $@
	@echo "==> so_long successfully compiled!"

libft:
	@make -C $(LIBFT_DIR)
	@echo "==> libft successfully created!"

libmlx42:
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4
	@echo "==> libmlx42 successfully created!"

clean:
	@rm -rf DEMO
	@make -C $(LIBFT_DIR) clean
	make -C $(LIBMLX_DIR)/build clean
	@echo "==> Simple clean done!"


fclean: clean
	@rm -rf $(TARGETS)
	@rm -rf DEMO
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(LIBMLX_DIR)/build
	@echo "==> Full clean done!"


re: fclean all