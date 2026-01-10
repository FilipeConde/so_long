/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:56:58 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/10 18:11:04 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_board(t_board *board)
{
	int	i;

	i = 0;
	if (!board || !board->map)
		return ((EXIT_SUCCESS));
	free_map(board->map);
	free(board);
	return (EXIT_SUCCESS);
}
