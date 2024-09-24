/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:38:06 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/24 21:47:38 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// cub3D: Error opening archive: Error reading 'maps'
/**
 * case_n 1 = map file
 * case_n 2 = texture files
*/
int	file_signature_check(int case_n, char *t_file)
{
	int		fd;
	ssize_t	offset;

	offset = 0;
	while (t_file[offset] != '\0')
		offset++;
	if (1 == case_n && strcmp_sst(t_file, ".cub", offset - 4) != 0)
		return (printf("cub3d: unknown suffix -- ignored '%s'\n", t_file));
	if (2 == case_n && strcmp_sst(t_file, ".xpm", offset - 4) != 0)
		return (printf("cub3d: unknown suffix -- ignored '%s'\n", t_file));
	fd = open(t_file, O_RDONLY);
	if (fd == -1)
		return (printf("cub3d: Error opening file: '%s'\n", t_file));
	close(fd);
	return (EXIT_SUCCESS);
}

static int	free_uncle(t_soul_catcher *game, char *processed_line, void *str)
{
	(free_textures(game->textures), free(processed_line));
	if (str)
		write(2, str++, 1);
	return (1);
}

int	set_game_data(t_soul_catcher *game, char *line, char **t_ids)
{
	int			i;
	char		*processed_line;

	i = -1;
	processed_line = ft_strtrim(line, WHITESPACE);
	while (t_ids[++i])
	{
		if (!ft_strncmp(processed_line, t_ids[i], ft_strlen(t_ids[i])))
		{
			if (game->map->full)
				return (free_uncle(game, processed_line, "Error: Map does not \
					follow the strict Order"));
			if (assign_texture(i, processed_line + ft_strlen(t_ids[i]), game))
				return (free_uncle(game, processed_line, NULL));
			break ;
		}
	}
	if (processed_line[0] == '1')
		return (update_map(game, processed_line, line));
	else if (processed_line[0] == '\n')
		return (printf("new line:"));
	return (free(processed_line), EXIT_SUCCESS);
}

int	extractfile(t_soul_catcher *game, int fd)
{
	char		*line;
	static char	*t_ids[7] = {"NO", "EA", "WE", "SO", "F", "C", NULL};

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
