/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:52:56 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/19 21:54:02 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangle(char **map)
{
	int	lines_qty;
	int	line_size;
	int	i;

	if (!map || !*map)
		return (-1);
	lines_qty = 0;
	while (map[lines_qty])
		lines_qty++;
	i = 0;
	line_size = ft_strlen(map[i]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != line_size)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	is_closed(char **map)
{
	int	lines_qty;
	int	line_size;
	int	i;

	if (!map || !*map)
		return (-1);
	lines_qty = 0;
	while (map[lines_qty])
		lines_qty++;
	i = 0;
	line_size = ft_strlen(map[0]);
	while (i < line_size)
	{
		if (map[0][i] != '1' || map[lines_qty - 1][i] != '1' )
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < lines_qty)
	{
		if (map[i][0] != '1' || map[i][line_size - 1] != '1' )
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	map_has_invalid_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'P'
					|| map[i][j] == 'C' || map[i][j] == 'E')
				j++;
			else
				return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}

int	map_checker(t_board *board)
{
	char	**map_copy;

	if (is_rectangle(board->map) != 0)
		return (EXIT_FAILURE);
	if (is_closed(board->map) != 0)
		return (EXIT_FAILURE);
	if (map_has_ent(board->map, 'P') != 0 || map_has_ent(board->map, 'C') != 0
		|| map_has_ent(board->map, 'E') != 0)
		return (EXIT_FAILURE);
	if (map_has_invalid_char(board->map) == 0)
		return (EXIT_FAILURE);
	map_copy = flood_fill(board);
	if (map_has_ent(map_copy, 'P') == 0 || map_has_ent(map_copy, 'C') == 0
		|| map_has_ent(map_copy, 'E') == 0)
	{
		free_map(map_copy);
		return (EXIT_FAILURE);
	}
	free_map(map_copy);
	return (EXIT_SUCCESS);
}
