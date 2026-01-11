/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:12:53 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/11 17:15:04 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_images(t_game *game)
{
	if (game->img_c)
		mlx_delete_image(game->mlx, game->img_c);
	if (game->img_p)
		mlx_delete_image(game->mlx, game->img_p);
	if (game->img_e)
		mlx_delete_image(game->mlx, game->img_e);
	if (game->img_w)
		mlx_delete_image(game->mlx, game->img_w);
	if (game->img_f)
		mlx_delete_image(game->mlx, game->img_f);
}