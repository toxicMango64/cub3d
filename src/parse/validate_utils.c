/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:53:02 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/22 13:30:49 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	is_surrounded_by_walls(t_soul_catcher *game, t_point *player_pos)
{
	char	**visited;

	visited = ft_tabdup(game->map->grid, 1);
	if (!is_closed(game, visited, player_pos->x, player_pos->y))
		return (freearr(visited), wrerr("Map must be surrounded by walls"));
	freearr(visited);
	return (EXIT_SUCCESS);
}
