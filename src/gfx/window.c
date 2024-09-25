/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:34:59 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/23 01:06:22 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	close_free(t_cub3d *cube)
// {
// 	if (cube->map.i_e)
// 		free_point(cube->map.i_e);
// 	if (cube->map.i_w)
// 		free_point(cube->map.i_w);
// 	if (cube->map.i_n)
// 		free_point(cube->map.i_n);
// 	if (cube->map.i_s)
// 		free_point(cube->map.i_s);
// 	if (cube->map.points)
// 		ft_freesplit(cube->map.points);
// 	if (cube->map.file_map)
// 		ft_freesplit(cube->map.file_map);
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

// int	handle_destroy(t_soul_catcher *game)
// {
// 	mlx_destroy_window(game->p_mlx, game->p_win);
// 	free(game->p_mlx);
// 	close(game->map->fd);
// 	free_textures(game->textures);
// 	freearr(game->map->grid);
// 	exit(0);
// 	return (0);
// }

// int	handle_keypress(int keysym, t_soul_catcher *game)
// {
// 	if (keysym == ESC)
// 		return (handle_destroy(game));
// 	return (0);
// }
