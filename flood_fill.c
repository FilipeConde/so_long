/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:50:11 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/10 02:46:13 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**cp_map(t_board *board)
{
	char	**map_cp;
	int		i;

	// create copy of map
	map_cp = (char **)ft_calloc(board->height + 1, sizeof(char *));
	if (!map_cp)
		return (NULL);
	i = 0;
	// start by player
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

int	flood_fill(t_board *board)
{
	int	i;
	char **map;

	map = cp_map(board);
	i = 0;
	if (!map)
		return (EXIT_FAILURE);
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	return (EXIT_SUCCESS);
	// check up, down, left and right
	// if different than '1' then set to '1' and do floodfill again
	// if '1', then go to the next
	// at the very end, check map for entities ('P', 'C', 'E')
	// 
}