/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_has_entity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:31:16 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/05 20:31:40 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_has_entity(char **map, char ent)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ent)
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		return (EXIT_FAILURE);
	if ((ent == 'P' || ent == 'E') && count > 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
