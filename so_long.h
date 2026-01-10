/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:55:46 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/10 17:19:04 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/MLX42/include/MLX42/MLX42.h"
# include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_board
{
	char	**map;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		c_qty;
}	t_board;

// add functions definitions
char	**read_map(char *path);
int		map_checker(t_board *board);
t_board	*set_board(char *path);
int		free_board(t_board *board);
int		map_has_ent(char **map, char ent);
char	**flood_fill(t_board *board);

#endif