/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mount_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:52:54 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/18 20:17:26 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	mount_window(t_board *board, t_game *game)
{
	game->mlx = mlx_init(((int32_t)board->width * TILE),
			((int32_t)board->height * TILE), "Test", true);
	set_sprites(game->mlx, game);
	print_board(board, game);
	mlx_key_hook(game->mlx, key_capture, game);
	mlx_loop(game->mlx);
	delete_images(game);
	mlx_terminate(game->mlx);
	free(game);
	return (EXIT_SUCCESS);
}
