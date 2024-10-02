/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:47:39 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 18:10:44 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_player_position(t_soul_catcher *game, t_point *player)
{
	int	x;
	int	y;

	y = -1;
	while (game->map->grid[++y])
	{
		x = -1;
		while (game->map->grid[y][++x])
		{
			if (ft_strchr("NEWS", game->map->grid[y][x]))
			{
				if (update_player(game, x, y) == EXIT_FAILURE)
					return (EXIT_FAILURE);
				break ;
			}
		}
	}
	if (!player->direction)
		return (perr("No player found"));
	game->map->width = y;
	return (EXIT_SUCCESS);
}

int	is_closed(t_soul_catcher *game, char **visited, int x, int y)
{
	if (y < 0 || x < 0 || y >= game->map->width
		|| x >= (int) ft_strlen(game->map->grid[y]))
		return (FALSE);
	if (game->map->grid[y][x] == '1' || visited[y][x] == '1')
		return (TRUE);
	else if (ft_strchr("0NEWS", game->map->grid[y][x]))
		visited[y][x] = '1';
	else if (x == 0 || ft_strchr(WHITESPACE, game->map->grid[y][x])
		|| y == 0 || y == game->map->width - 1)
		return (FALSE);
	if (!is_closed(game, visited, x, y - 1)
		|| !is_closed(game, visited, x + 1, y)
		|| !is_closed(game, visited, x, y + 1)
		|| !is_closed(game, visited, x - 1, y))
		return (FALSE);
	return (TRUE);
}

short int	check_zero_surrounding(t_soul_catcher *game)
{
	int		x;
	int		y;
	char	**map;

	y = -1;
	map = game->map->grid;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == '0')
				if (help_check_zero_surrounding(map, y, x) == EXIT_SUCCESS)
					continue ;
	}
	return (EXIT_SUCCESS);
}

int	is_surrounded_by_walls(t_soul_catcher *game, t_point *player_pos)
{
	char	**visited;

	visited = ft_tabdup(game->map->grid, 1, -1, -1);
	if (!is_closed(game, visited, player_pos->spawn_x, player_pos->spawn_y))
		return (freearr(visited), perr("Player must be surrounded by walls"));
	freearr(visited);
	if (check_zero_surrounding(game))
		return (perr("Map must be surrounded by walls"));
	return (EXIT_SUCCESS);
}

/**
 * if (!game->textures->floor) // shove in error check for more than 255 or
 * less than 0
 * 
 * if (!game->textures->ceiling) // shove in error check for more than 255 or
 * less than 0
*/
int	is_map_valid(t_soul_catcher *game)
{
	if (!game->map->full)
		return (perr("No map found"), EXIT_FAILURE);
	game->map->grid = ft_split(game->map->full, '\n');
	if (!game->map->grid)
		return (perr("gird malloc error -- No map found"));
	if (find_player_position(game, game->player_pos))
		return (EXIT_FAILURE);
	if (is_surrounded_by_walls(game, game->player_pos))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
