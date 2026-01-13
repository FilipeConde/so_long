/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:56:58 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/12 23:12:36 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_board(t_board *board)
{
	if (!board || !board->map)
		return ((EXIT_SUCCESS));
	free_map(board->map);
	free(board);
	return (EXIT_SUCCESS);
}
