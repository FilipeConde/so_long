/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mount_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:52:54 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/11 14:37:55 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	mount_window(void)
{
	mlx_t* mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Test", true);

	// Try to load the file
	mlx_texture_t* texture = mlx_load_png("./assets/skull.png");
	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	// Display the image
	mlx_image_to_window(mlx, img, 32, 32);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}