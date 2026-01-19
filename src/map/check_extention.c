/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 20:56:35 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/18 21:14:39 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extention(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '.')
		{
			i++;
			if (file[i] == 'b')
			{
				i++;
				if (file[i] == 'e')
				{
					i++;
					if (file[i] == 'r' && file[i + 1] == '\0')
					{
						return (EXIT_SUCCESS);
					}
				}
			}
		}
		i++;
	}
	return (EXIT_FAILURE);
}
