/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:47:39 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/21 20:59:57 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_player(t_soul_catcher *game, int x, int y)
{
	if (game->player_pos->direction)
		return (wrerr("Multiple players found"));
	game->player_pos->y = y;
	game->player_pos->x = x;
	game->player_pos->direction = game->map->grid[y][x];
	return (EXIT_SUCCESS);
}

int	has_invalid_chars(t_soul_catcher *game, t_point *player)
{
	int	x;
	int	y;

	y = -1;
	while (game->map->grid[++y])
	{
		x = -1;
		while (game->map->grid[y][++x])
		{
			if (!ft_strchr(WHITESPACE, game->map->grid[y][x]) \
				&& !ft_strchr("10NEWS", game->map->grid[y][x]))
				return (wrerr("Invalid character detected"));
			if (ft_strchr("NEWS", game->map->grid[y][x]))
				if (update_player(game, x, y) == EXIT_FAILURE)
					return (EXIT_FAILURE);
		}
	}
	if (!player->direction)
		return (wrerr("No player found"));
	game->map->width = y;
	return (EXIT_SUCCESS);
}

static int check_texture(const char *t_path, const char *t_name)
{
	int fd;

	if (!t_path)
		return (printf("cub3d: Error opening texture: '{%s}'\n", t_path));
	fd = open(t_path, O_RDONLY);
	if (fd == -1)
		return (perror(t_name), EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

int has_required_config(t_soul_catcher *game)
{
	if (check_texture(game->textures->north, "North texture"))
		return (printf("No north texture detected\n"));
	if (check_texture(game->textures->east, "East texture"))
		return (printf("No east texture detected\n"));
	if (check_texture(game->textures->west, "West texture"))
		return (printf("No west texture detected\n"));
	if (check_texture(game->textures->south, "South texture"))
		return (printf("No south texture detected\n"));
	if (!game->textures->floor) // shove up error check for more than 255 or less than 0
		return (printf("No floor texture detected\n"));
	if (!game->textures->ceiling) // shove up error check for more than 255 or less than 0
		return (printf("No ceiling texture detected\n"));
	if (!game->map->full)
		return (printf("No map found\n"));
	if (has_invalid_chars(game, game->player_pos))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_map_valid(t_soul_catcher *game)
{
	game->map->grid = ft_split(game->map->full, '\n');
	if (has_required_config(game))
		return (EXIT_FAILURE);
	else if (is_surrounded_by_walls(game, game->player_pos))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
