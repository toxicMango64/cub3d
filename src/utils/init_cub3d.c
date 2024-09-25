/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 06:42:14 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/26 02:35:39 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->width = 0;
	map->full = NULL;
	map->grid = NULL;
}

void	init_textures(t_textures *textures)
{
	textures->north = NULL;
	textures->east = NULL;
	textures->west = NULL;
	textures->south = NULL;
	textures->floor = NULL;
	textures->ceiling = NULL;
}

void	init_point(t_point *player)
{
	player->direction = '\0';
	player->spawn_x = '\0';
	player->spawn_y = '\0';
}

/** Initialize game state */
void	init_soul_catcher(t_soul_catcher *game, t_point *player, t_map *map, \
	t_textures *textures)
{
	init_map(map);
	init_point(player);
	init_textures(textures);
	game->p_mlx = NULL;
	game->p_win = NULL;
	game->map = map;
	game->player_pos = player;
	game->textures = textures;
}
