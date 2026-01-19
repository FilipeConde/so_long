/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:54:24 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/18 21:31:49 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_board	*board;
	t_game	*game;

	if (argc != 2)
		return (EXIT_FAILURE);
	board = set_board(argv[1]);
	if (!board)
	{
		ft_printf("Error\nBoard setup\n");
		free(board);
		return (EXIT_FAILURE);
	}
	game = set_game();
	if (!game)
	{
		ft_printf("Error\nGame setup\n");
		free_board(board);
		return (EXIT_FAILURE);
	}		
	game->board = board;
	game->moves = 0;
	mount_window(board, game);
	free_board(board);
	return (EXIT_SUCCESS);
}
