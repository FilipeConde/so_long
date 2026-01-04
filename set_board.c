/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:34:42 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/04 20:55:03 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_board	*set_board(char *path)
{
	t_board	*board;

	board = ft_calloc(sizeof(t_board), 1);
	board->map = read_map(path);
	return (board);
}
