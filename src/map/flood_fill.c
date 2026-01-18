/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:50:11 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/18 20:12:43 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**cp_map(t_board *board)
{
	char	**map_cp;
	int		i;

	map_cp = (char **)ft_calloc(board->height + 1, sizeof(char *));
	if (!map_cp)
		return (NULL);
	i = 0;
	while (i < board->height)
	{
		map_cp[i] = ft_strdup(board->map[i]);
		if (!map_cp[i])
		{
			while (--i >= 0)
				free(map_cp[i]);
			free(map_cp);
			return (NULL);
		}
		i++;
	}
	return (map_cp);
}

void	dfs_fill(char **map, int p_x, int p_y)
{
	if (map[p_x][p_y] == '1')
		return ;
	if (map[p_x][p_y] != '1')
		map[p_x][p_y] = '1';
	dfs_fill(map, p_x + 1, p_y);
	dfs_fill(map, p_x - 1, p_y);
	dfs_fill(map, p_x, p_y + 1);
	dfs_fill(map, p_x, p_y - 1);
}

char	**flood_fill(t_board *board)
{
	char	**map;

	map = cp_map(board);
	if (!map)
		return (NULL);
	dfs_fill(map, board->p_x, board->p_y);
	return (map);
}
