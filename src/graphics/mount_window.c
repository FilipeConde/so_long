/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mount_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:52:54 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/11 19:52:23 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	mount_window(t_board *board, t_game *game)
{
	game->mlx = mlx_init((board->width * TILE),
		(board->height * TILE), "Test", true);
	set_sprites(game->mlx, game);
	mlx_image_to_window(game->mlx, game->img_p, 2 * TILE, 2 * TILE);
	mlx_image_to_window(game->mlx, game->img_c, 3 * TILE, 3 * TILE);
	mlx_loop(game->mlx);
	delete_images(game);
	// mlx_delete_image(game->mlx, img);
	// mlx_delete_texture(texture);
	mlx_terminate(game->mlx);
	free(game);
	return (EXIT_SUCCESS);
}
