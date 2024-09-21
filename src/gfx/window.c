/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:34:59 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/21 23:19:44 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	close_x(t_soul_catcher *cube)
// {
// 	mlx_destroy_window(cube->mlx, cube->mlx->p_win);
// 	free(cube->mlx);
// 	close_free(cube);
// 	exit(0);
// 	return (0);
// }

// int	close_esc(int keycode, t_soul_catcher *cube)
// {
// 	(void) keycode;
// 	mlx_destroy_window(cube->mlx, cube->mlx->p_win);
// 	free(cube->mlx);
// 	close_free(cube);
// 	exit(0);
// 	return (0);
// }

#include "cub3d.h"

int	handle_destroy(t_soul_catcher *game)
{
	mlx_destroy_window(game->p_mlx, game->p_win);
	close(game->map->fd);
	free_textures(game->textures);
	freearr(game->map->grid);
	exit(0);
	return (0);
}

int	handle_keypress(int keysym, t_soul_catcher *game)
{
	if (keysym == ESC)
		return (handle_destroy(game));
	return (0);
}
