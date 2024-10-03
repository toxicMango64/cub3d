/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:38:06 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 23:04:28 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// return (free(trimmed), perr("map isn't surrounded by walls: %s", line));
int	check_assign_color(t_soul_catcher *game, char **color_value, \
	char **c_hex, int i)
{
	if (count_commas(color_value[1]) != 2)
		return (perr("invalid color format {R,G,B}"));
	if (ft_strncmp(color_value[0], "C", 1) == 0)
	{
		if (game->textures->ceiling)
			return (freearr(c_hex), perr("cu3d: C: RGB exists"));
		game->textures->ceiling = color_value[1];
	}
	else if (ft_strncmp(color_value[0], "F", 1) == 0)
	{
		if (game->textures->floor)
			return (freearr(c_hex), perr("cu3d: F: RGB exists"));
		game->textures->floor = color_value[1];
	}
	while (c_hex[++i])
	{
		if (__check_color(game, c_hex, color_value, i))
			return (perr("invalid RGB format"));
	}
	return (EXIT_SUCCESS);
}

// revised assign_texture and color
int	assign_texture_revised(t_soul_catcher *game, char **attribute_arr)
{
	char	**color;

	if ((ft_strncmp(attribute_arr[0], "C", 1) == 0
			|| ft_strncmp(attribute_arr[0], "F", 1) == 0))
	{
		color = ft_split(attribute_arr[1], ',');
		if (!color || !color[0] || !color[1] || !color[2] || color[3])
			return (freearr(color), perr("invalid texture"));
		if (check_assign_color(game, attribute_arr, color, -1))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	if (file_signature_check(TEXTURE, attribute_arr[1]))
		return (EXIT_FAILURE);
	if (is_set(game, attribute_arr))
		return (EXIT_FAILURE);
	else if (ft_strncmp(attribute_arr[0], "NO", 2) == 0)
		return (game->textures->north = attribute_arr[1], EXIT_SUCCESS);
	else if (ft_strncmp(attribute_arr[0], "SO", 2) == 0)
		return (game->textures->south = attribute_arr[1], EXIT_SUCCESS);
	else if (ft_strncmp(attribute_arr[0], "WE", 2) == 0)
		return (game->textures->west = attribute_arr[1], EXIT_SUCCESS);
	else if (ft_strncmp(attribute_arr[0], "EA", 2) == 0)
		return (game->textures->east = attribute_arr[1], EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	set_game_data(t_soul_catcher *game, char *line, char **t_ids, int *chk_att)
{
	char	**split;

	if (!(*chk_att))
	{
		if (line[0] == '1' || line[0] == '0')
			return (perr("missing texture/color"));
		split = ft_split(line, ' ');
		if (!split || !split[0] || !split[1] || split[2])
			return (freearr(split), perr("Txture/Color attribute failure"));
		if (valid_txture_color_name(t_ids, split[0]))
		{
			if (assign_texture_revised(game, split))
				return (EXIT_FAILURE);
			if (are_all_txtures_colors_set(game->textures))
				*chk_att = 1;
		}
		else
			return (freearr(split), perr("Invalid Txture/Color attribute"));
		return (EXIT_SUCCESS);
	}
	free(line);
	return (EXIT_SUCCESS);
}

int	parse_map(t_soul_catcher *game, char *line, int *map_started)
{
	char	*trimmed;

	*map_started = 1;
	trimmed = ft_strtrim(line, "\n");
	if (!trimmed)
		return (perr("Failed to trim map line"));
	if (trimmed[0] == '\0')
		return (free(trimmed), perr("invalid map"));
	if (check_invalid_char(trimmed))
		return (free(trimmed), perr("invalid line in map: %s", line));
	update_map(game, line);
	free(trimmed);
	return (EXIT_SUCCESS);
}

int	extractfile(t_soul_catcher *game, char *line, int fd)
{
	static char	*t_ids[7] = {"NO", "EA", "WE", "SO", "F", "C", NULL};
	static int	chk_att;
	static int	map_started;

	while (line)
	{
		if (!chk_att && line[0] != '\n')
		{
			if (set_game_data(game, ft_strtrim(line, WHITESPACE), t_ids, \
				&chk_att))
				return (free(line), EXIT_FAILURE);
		}
		else if (chk_att)
		{
			if (!map_started && line[0] == '\n')
			{
				(free(line), line = get_next_line(fd));
				continue ;
			}
			if (parse_map(game, line, &map_started))
				return (free(line), EXIT_FAILURE);
		}
		(free(line), line = get_next_line(fd));
	}
	return (EXIT_SUCCESS);
}
