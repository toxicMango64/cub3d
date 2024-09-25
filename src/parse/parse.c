/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:38:06 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/22 13:26:32 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// cub3D: Error opening archive: Error reading 'maps'
int	file_signature_check(int case_n, const char *t_file)
{
	int		fd;
	ssize_t	offset;

	offset = 0;
	while (t_file[offset] != '\0')
		offset++;
	if (1 == case_n && strcmp_sst(t_file, ".cub", offset - 4))
		return (printf("cub3d: unknown suffix '%s' -- ignored", t_file));
	else if (2 == case_n && strcmp_sst(t_file, ".xpm", offset - 4))
		return (printf("cub3d: unknown suffix '%s' -- ignored", t_file));
	fd = open(t_file, O_RDONLY);
	if (fd == -1)
		return (printf("cub3d: Error opening file: Error reading 'map'"));
	close(fd);
	return (EXIT_SUCCESS);
}

int	set_game_data(t_soul_catcher *game, char *line, char **t_ids)
{
	int		i;
	char	*processed_line;

	processed_line = ft_strtrim(line, WHITESPACE);
	if (processed_line[0] == '1')
		return (update_map(game, processed_line, line));
	else if (processed_line[0] == '\n')
		return (printf("new line:"));
	i = -1;
	while (t_ids[++i])
	{
		if (!ft_strncmp(processed_line, t_ids[i], ft_strlen(t_ids[i])))
		{
			if (game->map->full)
				return (free_textures(game->textures), free(processed_line), \
					wrerr("Error: Map does not follow the strict Order"));
			if (assign_texture(i, processed_line + ft_strlen(t_ids[i]), game))
				return (free_textures(game->textures), \
					free(processed_line), EXIT_FAILURE);
			break ;
		}
	}
	return (free(processed_line), EXIT_SUCCESS);
}

char	**intit_texture(void)
{
	static char	*t_id[7] = {"NO", "EA", "WE", "SO", "F", "C", NULL};

	return (t_id);
}

int	extractfile(t_soul_catcher *game, int fd)
{
	char	*line;
	char	**t_ids;

	t_ids = intit_texture();
	line = ft_strdup("");
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] || line[0] == '\n')
		{
			if (set_game_data(game, line, t_ids))
				return (free(line), EXIT_FAILURE);
			free(line);
			line = ft_strdup("");
		}
	}
	return (free(line), EXIT_SUCCESS);
}
// int	validate_map(const char *path_to_map, t_soul_catcher *game)
// {
// 	int	fd;

// 	map_signature_check(path_to_map);
// 	fd = open(path_to_map, O_RDONLY);
// 	(extractfile(game, fd), close(fd));

// 	printconent(game);
// 	return (EXIT_SUCCESS);
// }
