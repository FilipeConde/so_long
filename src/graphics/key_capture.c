/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_capture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 23:05:11 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/13 23:22:28 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_capture(mlx_key_data_t keydata, void *param)
{
	char	*c;

	c = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		ft_printf("UP");
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		ft_printf("DOWN");
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		ft_printf("LEFT");
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		ft_printf("RIGHT");
}