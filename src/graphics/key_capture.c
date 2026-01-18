/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_capture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 23:05:11 by fconde-p          #+#    #+#             */
/*   Updated: 2026/01/18 17:22:30 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game)
{
	int	p_x;
	int	p_y;
	p_x = game->board->p_x;
	p_y = game->board->p_y;

	if (game->board->map[p_x - 1][p_y] == '1')
		return ;
	p_x--;
	update_p_pos(p_x, p_y, game);
	game->img_p->instances[0].y -= TILE;
	if (game->board->map[p_x][p_y] == 'C')
		do_collect(game);
	if (game->board->map[p_x][p_y] == 'E' && game->img_e->enabled == true)
		do_win(game);
}

static void	move_down(t_game *game)
{
	int	p_x;
	int	p_y;
	p_x = game->board->p_x;
	p_y = game->board->p_y;

	if (game->board->map[p_x + 1][p_y] == '1')
		return ;
	p_x++;
	update_p_pos(p_x, p_y, game);
	game->img_p->instances[0].y += TILE;
	if (game->board->map[p_x][p_y] == 'C')
		do_collect(game);
	if (game->board->map[p_x][p_y] == 'E' && game->img_e->enabled == true)
		do_win(game);
}

static void	move_left(t_game *game)
{
	int	p_x;
	int	p_y;
	p_x = game->board->p_x;
	p_y = game->board->p_y;

	if (game->board->map[p_x][p_y - 1] == '1')
		return ;
	p_y--;
	update_p_pos(p_x, p_y, game);
	game->img_p->instances[0].x -= TILE;
	if (game->board->map[p_x][p_y] == 'C')
		do_collect(game);
	if (game->board->map[p_x][p_y] == 'E' && game->img_e->enabled == true)
		do_win(game);
}

static void	move_right(t_game *game)
{
	int	p_x;
	int	p_y;
	p_x = game->board->p_x;
	p_y = game->board->p_y;

	if (game->board->map[p_x][p_y + 1] == '1')
		return ;
	p_y++;
	update_p_pos(p_x, p_y, game);
	game->img_p->instances[0].x += TILE;
	if (game->board->map[p_x][p_y] == 'C')
		do_collect(game);
	if (game->board->map[p_x][p_y] == 'E' && game->img_e->enabled == true)
		do_win(game);
}


void	key_capture(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	(void)keydata;
	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move_up(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move_down(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		move_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("No problemo, better luck on next try!\n");
		mlx_close_window(game->mlx);
	}
}
