/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:58:56 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 21:31:57 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	free_parse(t_soul_catcher *game)
{
	if (game->map->full)
		free(game->map->full);
	if (game->map->grid)
		freearr(game->map->grid);
	if (game->textures)
		free_textures(game->textures);
}

void	exit_init(t_soul_catcher *game, char *str)
{
	if (game->p_mlx && game->map->grid && game->frame.ptr)
		mlx_destroy_image(game->p_mlx, game->frame.ptr);
	if (game->p_win)
		mlx_destroy_window(game->p_mlx, game->p_win);
	if (game->p_mlx)
		free(game->p_mlx);
	free_parse(game);
	if (str)
		perr(str);
	exit (1);
}

void	destroy_img(t_soul_catcher *game)
{
	if (game->frame.ptr)
		mlx_destroy_image(game->p_mlx, game->frame.ptr);
	if (game->north.ptr)
		mlx_destroy_image(game->p_mlx, game->north.ptr);
	if (game->south.ptr)
		mlx_destroy_image(game->p_mlx, game->south.ptr);
	if (game->east.ptr)
		mlx_destroy_image(game->p_mlx, game->east.ptr);
	if (game->west.ptr)
		mlx_destroy_image(game->p_mlx, game->west.ptr);
}

int	close_game(t_soul_catcher *game)
{
	destroy_img(game);
	mlx_destroy_window(game->p_mlx, game->p_win);
	free(game->p_mlx);
	free_parse(game);
	exit (0);
}
