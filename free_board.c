/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:56:58 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/05 18:48:22 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_board(t_board *board)
{
	int	i;

	i = 0;
	if (!board || !board->map)
		return ((EXIT_SUCCESS));
	while (i < board->height)
	{
		if (board->map[i])
		{
			free(board->map[i]);
			board->map[i] = NULL;
		}
		i++;
	}
	free(board->map);
	board->map = NULL;
	free(board);
	return (EXIT_SUCCESS);
}
