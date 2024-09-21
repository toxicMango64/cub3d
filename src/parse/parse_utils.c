/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:38:03 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/21 21:29:47 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_map(t_soul_catcher *game, char *processed_line, char *line)
{
	char	*temp;

	if (!game->map->full)
		game->map->full = ft_strdup("");
	temp = game->map->full;
	// printf("%s\n", processed_line);
	// if (strpbrk(processed_line, WHITESPACE))
	// {
	// 	printf("Error: Map does not follow the strict Order");
	// 	return (EXIT_FAILURE);
	// }
	game->map->full = ft_strjoin(game->map->full, line);
	return (free(temp), free(processed_line), EXIT_SUCCESS);
}

int	is_set(t_soul_catcher *game, t_texture_type type)
{
	if (type == NORTH && game->textures->north)
		return (printf("Duplicate north texture detected.\n"));
	if (type == EAST && game->textures->east)
		return (printf("Duplicate east texture detected.\n"));
	if (type == WEST && game->textures->west)
		return (printf("Duplicate west texture detected.\n"));
	if (type == SOUTH && game->textures->south)
		return (printf("Duplicate south texture detected.\n"));
	if (type == FLOOR && game->textures->floor)
		return (printf("Duplicate floor texture detected.\n"));
	if (type == CEILING && game->textures->ceiling)
		return (printf("Duplicate ceiling texture detected.\n"));
	return (EXIT_SUCCESS);
}

int	assign_texture(t_texture_type type, char *texture, t_soul_catcher *game)
{
	if (is_set(game, type))
		return (EXIT_FAILURE);
	if (type == NORTH)
		game->textures->north = ft_strtrim(texture, WHITESPACE);
	else if (type == EAST)
		game->textures->east = ft_strtrim(texture, WHITESPACE);
	else if (type == WEST)
		game->textures->west = ft_strtrim(texture, WHITESPACE);
	else if (type == SOUTH)
		game->textures->south = ft_strtrim(texture, WHITESPACE);
	else if (type == FLOOR)
		game->textures->floor = ft_strtrim(texture, WHITESPACE);
	else if (type == CEILING)
		game->textures->ceiling = ft_strtrim(texture, WHITESPACE);
	return (EXIT_SUCCESS);
}
