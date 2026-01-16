/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_capture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 23:05:11 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/15 22:24:24 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	move_up(t_game *game)
// {
// 	int		next_y;
// 	int		next_x;
// 	char	next_pos;

// 	next_y = game->board->p_y - 1;
// 	next_x = game->board->p_x;
// 	next_pos = game->board->map[next_y][next_x];
// 	if (next_pos == '1')
// 		return ;
// 	if (next_pos == 'E' && game->board->c_qty > 0)
// 		return ;
// 	if (next_pos == 'E' && game->board->c_qty == 0)
// 	{
// 		ft_printf("You won!\n");
// 		exit(EXIT_SUCCESS);
// 	}
// 	if (next_pos == 'C')
// 		game->board->c_qty--;
// 	game->board->map[game->board->p_y][game->board->p_x] = '0';
// 	game->img_p->instances[0].y += TILE;
// 	game->board->map[game->board->p_y][game->board->p_x] = 'P';
// 	print_board(game->board, game);
// }

// static void	move_down(t_game *game)
// {
// 	// Implement move down logic
// }

// static void	move_left(t_game *game)
// {
// 	// Implement move left logic
// }

// static void	move_right(t_game *game)
// {
// 	// Implement move right logic
// }


void	key_capture(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->img_p->instances[0].x += TILE;

//		move_up(game);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_printf("So long!\nAnd thanks for all the skulls!\n");
		mlx_close_window(game->mlx);
	}
}
