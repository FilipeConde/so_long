/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:55:46 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/18 21:03:00 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define TILE 64

typedef struct s_board
{
	char	**map;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		c_qty;
	int		c_total;
}	t_board;

typedef struct s_game
{
	t_board		*board;
	int			moves;
	mlx_t		*mlx;
	mlx_image_t	*img_p;
	mlx_image_t	*img_c;
	mlx_image_t	*img_e;
	mlx_image_t	*img_f;
	mlx_image_t	*img_w;
}	t_game;

char	**read_map(char *path);
int		map_checker(t_board *board);
t_board	*set_board(char *path);
int		free_board(t_board *board);
int		map_has_ent(char **map, char ent);
char	**flood_fill(t_board *board);
int		free_map(char **map);
int32_t	mount_window(t_board *board, t_game *game);
void	delete_images(t_game *game);
void	set_sprites(mlx_t *mlx, t_game *game);
t_game	*set_game(void);
void	print_board(t_board *board, t_game *game);
void	key_capture(mlx_key_data_t keydata, void *param);
void	update_p_pos(int x, int y, t_game *game);
void	do_collect(t_game *game);
void	do_win(t_game *game);
int		check_extention(char *file);

void	mlx_key_hook(mlx_t *mlx, mlx_keyfunc func, void *param);

#endif