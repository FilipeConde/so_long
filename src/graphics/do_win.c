/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:17:13 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/18 21:50:01 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_win(t_game *game)
{
	ft_printf("So long!\nAnd thanks for all the trash!\n");
	mlx_close_window(game->mlx);
}
