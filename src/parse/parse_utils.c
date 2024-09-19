/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:38:03 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/19 06:12:58 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_map(t_soul_catcher *data, char *processed_line, char *line)
{
	char	*temp;

	if (!data->map->full)
		data->map->full = ft_strdup("");
	temp = data->map->full;
	data->map->full = ft_strjoin(data->map->full, line);
	return (free(temp), free(processed_line), EXIT_SUCCESS);
}

void	free_textures(t_textures *textures)
{
	printf("<<<<<<<<<<<HERE>>>>>>>>>>>\n");
	if (printf("texture: {%s}\n", textures->north) && textures->north)
		free(textures->north);
	if (printf("texture: {%s}\n", textures->east) && textures->east)
		free(textures->east);
	if (printf("texture: {%s}\n", textures->west) && textures->west)
		free(textures->west);
	if (printf("texture: {%s}\n", textures->south) && textures->south)
		free(textures->south);
	if (printf("texture: {%s}\n", textures->floor) && textures->floor)
		free(textures->floor);
	if (printf("texture: {%s}\n", textures->ceiling) && textures->ceiling)
		free(textures->ceiling);
}

int	is_set(t_soul_catcher *game, t_texture_type type)
{
	if (type == NORTH && game->textures->north)
		return (wrerr("Duplicate north texture detected."));
	if (type == EAST && game->textures->east)
		return (wrerr("Duplicate east texture detected."));
	if (type == WEST && game->textures->west)
		return (wrerr("Duplicate west texture detected."));
	if (type == SOUTH && game->textures->south)
		return (wrerr("Duplicate south texture detected."));
	if (type == FLOOR && game->textures->floor)
		return (wrerr("Duplicate floor texture detected."));
	if (type == CEILING && game->textures->ceiling)
		return (wrerr("Duplicate ceiling texture detected."));
	return (EXIT_SUCCESS);
}

int	assign_texture(t_texture_type type, char *texture, t_soul_catcher *game)
{
	if (is_set(game, type) == EXIT_FAILURE)
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

int	set_game_data(t_soul_catcher *game, char *line, char **t_ids)
{
	int		i;
	char	*processed_line;

	processed_line = ft_strtrim(line, WHITESPACE);
	if (processed_line[0] == '1')
		return (update_map(game, processed_line, line));
	i = -1;
	while (t_ids[++i])
	{
		if (!ft_strncmp(processed_line, t_ids[i], ft_strlen(t_ids[i])))
		{
			if (game->map->full)
				return (free_textures(game->textures), free(processed_line), \
					wr("Error: Invalid Map Order"));
			if (assign_texture(i, processed_line + ft_strlen(t_ids[i]), \
				game) == EXIT_FAILURE)
				return (free_textures(game->textures), \
					free(processed_line), EXIT_FAILURE);
			break ;
		}
	}
	return (free(processed_line), EXIT_SUCCESS);
}
