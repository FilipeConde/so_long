/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:34:42 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/05 18:38:03 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map_dimensions(t_board *board)
{
	int	height;
	int	width;
	int	i;

	height = 0;
	width = 0;
	i = 0;
	while (board->map[i])
	{
		height++;
		i++;
	}
	board->height = height;
	i = 0;
	while (board->map[0][i])
	{
		width++;
		i++;
	}
	board->width = width;
}

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
	set_map_dimensions(board);
	if (map_checker(board->map) != 0)
	{
		free_board(board);
		board = NULL;
		return (board);
	}
	return (board);
}
