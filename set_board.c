/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:34:42 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/04 21:27:19 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_board	*set_board(char *path)
{
	t_board	*board;

	board = ft_calloc(sizeof(t_board), 1);
	if (!board)
	{
		free_board(board);
		board = NULL;
		return (board);
	}
	board->map = read_map(path);
	if (map_checker(board->map) != 0)
	{
		free_board(board);
		board = NULL;
		return (board);
	}
	return (board);
}
