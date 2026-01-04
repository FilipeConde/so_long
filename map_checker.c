/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:52:56 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/04 14:31:42 by fconde-p         ###   ########.fr       */
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

int	map_checker(char **map)
{
	if (!is_rectangle(map))
		return (EXIT_FAILURE);
	// is_closed(**map);
	// has_entities(**map);

	return (EXIT_SUCCESS);
}