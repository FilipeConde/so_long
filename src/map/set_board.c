/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:34:42 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/18 20:59:16 by fconde-p         ###   ########.fr       */
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

static void	set_entity_position(t_board *board, char ent, int x, int y)
{
	if (ent == 'P')
	{
		board->p_x = x;
		board->p_y = y;
	}
	else if (ent == 'E')
	{
		board->e_x = x;
		board->e_y = y;
	}
}

static void	search_entities_position(t_board *board, char ent)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (board->map[i])
	{
		while (board->map[i][j])
		{
			if (board->map[i][j] == ent)
			{
				set_entity_position(board, ent, i, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	count_collectables(t_board *board)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (board->map[i])
	{
		while (board->map[i][j])
		{
			if (board->map[i][j] == 'C')
			{
				count++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	board->c_qty = count;
	board->c_total = count;
}

t_board	*set_board(char *path)
{
	t_board	*board;

	if (check_extention(path) == 1)
		return (NULL);
	board = ft_calloc(sizeof(t_board), 1);
	if (!board)
	{
		free_board(board);
		board = NULL;
		return (board);
	}
	board->map = read_map(path);
	set_map_dimensions(board);
	search_entities_position(board, 'P');
	search_entities_position(board, 'E');
	count_collectables(board);
	if (map_checker(board) != 0)
	{
		free_board(board);
		board = NULL;
		return (board);
	}
	return (board);
}
