/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:58:43 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/18 16:27:50 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_player(t_board *board, t_game *game)
{
	mlx_image_to_window(game->mlx, game->img_p,
		board->p_y * TILE, board->p_x * TILE);
}

static void	print_exit(t_board *board, t_game *game)
{
	mlx_image_to_window(game->mlx, game->img_e,
		board->e_y * TILE, board->e_x * TILE);
}

static void	print_collectable(t_board *board, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (board->map[i])
	{
		while (board->map[i][j])
		{
			if (board->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->img_c, j * TILE, i * TILE);
			j++;
		}
		i++;
		j = 0;
	}
}

void	print_board(t_board *board, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (board->map[i])
	{
		while (board->map[i][j])
		{
			if (board->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->img_w, j * TILE, i * TILE);
			else
				mlx_image_to_window(game->mlx, game->img_f, j * TILE, i * TILE);
			j++;
		}
		i++;
		j = 0;
	}
	print_player(board, game);
	print_collectable(board, game);
	print_exit(board, game);
}
