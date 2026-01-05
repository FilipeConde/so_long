/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:54:24 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/04 21:21:00 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// code as hell!!!
int	main(int argc, char **argv)
{
	t_board	*board;
	int		i;

	if (argc != 2)
		return (EXIT_FAILURE);
	board = set_board(argv[1]);
	if (!board)
	{
		ft_printf("Board setup error\n");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (board->map[i])
	{
		ft_printf("%s\n", board->map[i]);
		i++;
	}
	ft_printf("%d\n", map_checker(board->map));
	return (EXIT_SUCCESS);
}
