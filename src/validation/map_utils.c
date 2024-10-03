/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:47:39 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/03 20:34:01 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_player(t_soul_catcher *game, int x, int y)
{
	game->player_pos->spawn_y = y;
	game->player_pos->spawn_x = x;
	game->player_pos->direction = game->map->grid[y][x];
	game->map->grid[y][x] = '0';
	if (game->player_pos->spawn_y == 0)
		return (perr("Player must be surrounded by walls"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	help_check_zero_surrounding(char **map, int y, int x)
{
	if (y == 0 || x == 0)
		return (EXIT_FAILURE);
	else if (!map[y][x + 1])
		return (EXIT_FAILURE);
	else if (!map[y + 1])
		return (EXIT_FAILURE);
	else
	{
		if (map[y - 1][x] == ' ')
			return (EXIT_FAILURE);
		if (map[y + 1][x] == ' ')
			return (EXIT_FAILURE);
		if (map[y][x - 1] == ' ')
			return (EXIT_FAILURE);
		if (map[y][x + 1] == ' ')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
