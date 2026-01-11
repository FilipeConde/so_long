/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:54:24 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/11 17:22:28 by fconde-p         ###   ########.fr       */
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
		ft_printf("Board setup error\n");
		free(board);
		return (EXIT_FAILURE);
	}
	game = set_game();
	mount_window(board, game);
	free_board(board);
	return (EXIT_SUCCESS);
}
