/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:54:24 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/03 21:00:56 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// code as hell!!!
int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	if (argc != 2)
		return (EXIT_FAILURE);
	map = read_map(argv[1]);
	if (!map)
	{
		ft_printf("Erro ao ler o mapa\n");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}