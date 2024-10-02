/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 06:42:14 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 17:43:49 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_map(t_map *map)
{
	map->fd = 0;
	map->floor_color[0] = 0;
	map->floor_color[1] = 0;
	map->floor_color[2] = 0;
	map->ceiling_color[0] = 0;
	map->ceiling_color[1] = 0;
	map->ceiling_color[2] = 0;
	map->width = 0;
	map->height = 0;
	map->full = NULL;
	map->grid = NULL;
	return (EXIT_SUCCESS);
}

int	init_texture(t_textures *textures)
{
	textures->north = NULL;
	textures->east = NULL;
	textures->west = NULL;
	textures->south = NULL;
	textures->floor = NULL;
	textures->ceiling = NULL;
	return (EXIT_SUCCESS);
}

/** Initialize game state */
int	init_soul_catcher(t_soul_catcher *game)
{
	if (!game)
		return (1);
	game->p_mlx = NULL;
	game->p_win = NULL;
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map || init_map(game->map))
		return (perror("map ft_calloc"), free_soul_catcher(game), 1);
	game->textures = ft_calloc(1, sizeof(t_textures));
	if (!game->textures || init_texture(game->textures))
		return (perror("textures ft_calloc"), free_soul_catcher(game), 1);
	game->player_pos = ft_calloc(1, sizeof(t_point));
	if (!game->player_pos)
		return (perror("player_pos ft_calloc"), free_soul_catcher(game), 1);
	game->player_pos->spawn_x = 0;
	game->player_pos->spawn_y = 0;
	game->player_pos->direction = '\0';
	return (EXIT_SUCCESS);
}
