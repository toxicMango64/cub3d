/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:32:25 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/03 20:35:13 by myousaf          ###   ########.fr       */
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

int	is_closed_zero(t_soul_catcher *game, char **visited, int x, int y)
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
