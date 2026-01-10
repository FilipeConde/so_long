/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:54:24 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/10 02:40:10 by fconde-p         ###   ########.fr       */
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
		free(board);
		return (EXIT_FAILURE);
	}
	ft_printf("QTY C: %d\n", board->c_qty);
	ft_printf("POS P:%d %d\n", board->p_x, board->p_y);
	ft_printf("POS E:%d %d\n", board->e_x, board->e_y);
	i = 0;
	// while (board->map[i])
	// {
	// 	ft_printf("%s\n", board->map[i]);
	// 	i++;
	// }

	// ft_printf("%d\n", map_checker(board->map));
	// if (map_checker(board->map) != 0)
	// {
	// 	free_board(board);
	// 	ft_printf("Invalid board\n");
	// 	return (EXIT_FAILURE);
	// }
	flood_fill(board);
	free_board(board);
	return (EXIT_SUCCESS);
}
