/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:42:34 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/18 20:06:37 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player(mlx_t *mlx, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./assets/raccoon.png");
	img = mlx_texture_to_image(mlx, texture);
	game->img_p = img;
	mlx_delete_texture(texture);
}

void	set_collectable(mlx_t *mlx, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./assets/apple.png");
	img = mlx_texture_to_image(mlx, texture);
	game->img_c = img;
	mlx_delete_texture(texture);
}

void	set_exit(mlx_t *mlx, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./assets/box.png");
	img = mlx_texture_to_image(mlx, texture);
	game->img_e = img;
	mlx_delete_texture(texture);
}

void	set_sprites(mlx_t *mlx, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img_f;
	mlx_image_t		*img_w;

	texture = mlx_load_png("./assets/floor.png");
	img_f = mlx_texture_to_image(mlx, texture);
	game->img_f = img_f;
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/wall.png");
	img_w = mlx_texture_to_image(mlx, texture);
	game->img_w = img_w;
	mlx_delete_texture(texture);
	set_collectable(mlx, game);
	set_player(mlx, game);
	set_exit(mlx, game);
}
