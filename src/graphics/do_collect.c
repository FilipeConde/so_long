/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:36:32 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/18 20:15:33 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_collect(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->board->c_total)
	{
		if (game->img_c->instances[i].x == game->img_p->instances[0].x
			&& game->img_c->instances[i].y == game->img_p->instances[0].y)
			game->img_c->instances[i].enabled = false;
		i++;
	}
	game->board->c_qty--;
	if (game->board->c_qty == 0)
		game->img_e->enabled = true;
}
