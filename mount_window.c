/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mount_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:52:54 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/10 20:00:34 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	mount_window(void)
{
	mlx_t* mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Test", true);
	mlx_loop(mlx);
	// mlx_delete_image(mlx, img);
	// mlx_delete_xpm42(xpm);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}