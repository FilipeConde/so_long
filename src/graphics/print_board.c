/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:58:43 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/11 20:35:18 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_board(t_board *board, t_game *game)
{
	// read board
	// to each position, put the right element on window
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (board->map[i])
	{
		// j = 0;
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
}