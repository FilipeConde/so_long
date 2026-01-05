/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:52:56 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/05 20:48:24 by fconde-p         ###   ########.fr       */
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

int	map_checker(char **map)
{
	if (is_rectangle(map) != 0)
		return (EXIT_FAILURE);
	if (is_closed(map) != 0)
		return (EXIT_FAILURE);
	if (map_has_entity(map, 'P') != 0 || map_has_entity(map, 'C') != 0
		|| map_has_entity(map, 'E') != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
