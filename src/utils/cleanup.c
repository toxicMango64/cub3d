/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 06:38:37 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/05 12:18:20 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_textures *textures)
{
	if (!textures)
		return ;
	if (textures->north)
		free(textures->north);
	if (textures->east)
		free(textures->east);
	if (textures->west)
		free(textures->west);
	if (textures->south)
		free(textures->south);
	if (textures->floor)
		free(textures->floor);
	if (textures->ceiling)
		free(textures->ceiling);
	free(textures);
}

// Helper free functions for each struct
void	free_map(t_map *map)
{
	ssize_t	i;

	if (0 < map->fd)
		close(map->fd);
	if (map->full)
		free(map->full);
	if (map->grid)
	{
		i = -1;
		while (map->grid[++i])
			free(map->grid[i]);
		free(map->grid);
	}
	free(map);
}

void	free_mlx(t_soul_catcher *game)
{
	if (game->frame.ptr)
		mlx_destroy_image(game->p_mlx, game->frame.ptr);
	if (game->frame.adr)
		free(game->frame.adr);
	if (game->north.ptr)
		mlx_destroy_image(game->p_mlx, game->north.ptr);
	if (game->north.adr)
		free(game->north.adr);
	if (game->south.ptr)
		mlx_destroy_image(game->p_mlx, game->south.ptr);
	if (game->south.adr)
		free(game->south.adr);
	if (game->west.ptr)
		mlx_destroy_image(game->p_mlx, game->west.ptr);
	if (game->west.adr)
		free(game->west.adr);
	if (game->east.ptr)
		mlx_destroy_image(game->p_mlx, game->east.ptr);
	if (game->east.adr)
		free(game->east.adr);
	if (game->p_win)
		mlx_destroy_window(game->p_mlx, game->p_win);
}

// Free function
void	free_soul_catcher(t_soul_catcher *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map);
	if (game->textures)
		free_textures(game->textures);
	if (game->player_pos)
		free(game->player_pos);
	if (game->ray)
		free(game->ray);
	if (game->player)
		free(game->player);
	free_mlx(game);
	free(game);
}
