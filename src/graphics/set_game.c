/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:21:15 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/11 17:25:42 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*set_game()
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
	{
		free(game);
		game = NULL;
	}
	return (game);
}
