/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:58:56 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 21:30:36 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_w(t_soul_catcher *game)
{
	double	x;
	double	y;

	x = game->player->pos_x + game->player->dir_x * MOVE_SPEED;
	y = game->player->pos_y + game->player->dir_y * MOVE_SPEED;
	if (check_move(game, x, y))
		game->draw_flag = 1;
}

void	move_s(t_soul_catcher *game)
{
	double	x;
	double	y;

	x = game->player->pos_x - game->player->dir_x * MOVE_SPEED;
	y = game->player->pos_y - game->player->dir_y * MOVE_SPEED;
	if (check_move(game, x, y))
		game->draw_flag = 1;
}

void	move_a(t_soul_catcher *game)
{
	double	x;
	double	y;

	x = game->player->pos_x - game->player->dir_y * MOVE_SPEED;
	y = game->player->pos_y + game->player->dir_x * MOVE_SPEED;
	if (check_move(game, x, y))
		game->draw_flag = 1;
}

void	move_d(t_soul_catcher *game)
{
	double	x;
	double	y;

	x = game->player->pos_x + game->player->dir_y * MOVE_SPEED;
	y = game->player->pos_y - game->player->dir_x * MOVE_SPEED;
	if (check_move(game, x, y))
		game->draw_flag = 1;
}
