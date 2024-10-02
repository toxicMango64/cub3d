/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:18:46 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 18:58:24 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

int	key_rotate(int sign, t_soul_catcher *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = 0;
	old_plane_x = 0;
	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos(sign * ROTATE_SPEED) \
	- game->player->dir_y * sin(sign * ROTATE_SPEED);
	game->player->dir_y = old_dir_x * sin(sign * ROTATE_SPEED) + \
	game->player->dir_y * cos(sign * ROTATE_SPEED);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(sign * ROTATE_SPEED) \
	- game->player->plane_y * sin(sign * ROTATE_SPEED);
	game->player->plane_y = old_plane_x * sin(sign * ROTATE_SPEED) \
	+ game->player->plane_y * cos(sign * ROTATE_SPEED);
	game->draw_flag = 1;
	return (0);
}

int	key_move(int keycode, t_soul_catcher *game)
{
	if (keycode == ESC)
		close_game(game);
	else if (keycode == W)
		move_w(game);
	else if (keycode == S)
		move_s(game);
	else if (keycode == A)
		move_a(game);
	else if (keycode == D)
		move_d(game);
	else if (keycode == L)
		key_rotate(1, game);
	else if (keycode == R)
		key_rotate(-1, game);
	return (0);
}
