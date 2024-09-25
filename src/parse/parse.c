/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:38:06 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/26 02:22:40 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// cub3D: Error opening file: Error reading 'filename'
int	file_signature_check(int case_n, const char *t_file, const char *prog)
{
	int		fd;
	ssize_t	offset;

	offset = 0;
	while (t_file[offset] != '\0')
		offset++;
	if (1 == case_n && strcmp_sst(t_file, ".cub", offset - 4))
		return (printf("%s: unknown suffix '%s' -- ignored", prog, t_file));
	else if (2 == case_n && strcmp_sst(t_file, ".xpm", offset - 4))
		return (printf("%s: unknown suffix '%s' -- ignored", prog, t_file));
	fd = open(t_file, O_RDONLY);
	if (fd == -1)
		return (printf("%s: %s '%s'", prog, FILEOPEN, t_file));
	close(fd);
	return (EXIT_SUCCESS);
}

int	ret__(t_soul_catcher *game, char *line, int case_n)
{
	(free_textures(game->textures), free(line));
	if (case_n)
		wrerr("Map does not follow the strict Order");
	return (1);
}

int	set_game_data(t_soul_catcher *game, char *line, char **t_ids)
{
	int			i;
	static int	texture_count;
	char		*processed_line;

	i = -1;
	processed_line = ft_strtrim(line, WHITESPACE);
	// printf ("line: {%s}\n", processed_line);
	while (t_ids[++i] && 6 > texture_count)
	{
		if (!ft_strncmp(processed_line, t_ids[i], ft_strlen(t_ids[i])))
		{
			if (game->map->full)
				return (ret__(game, processed_line, 1));
			if (assign_texture(i, processed_line + ft_strlen(t_ids[i]), game))
				return (ret__(game, processed_line, 0));
			texture_count += 1;
			return (free(processed_line), EXIT_SUCCESS);
			// break ;
		}
	}
	if (processed_line[0] == '1')
		return (update_map(game, processed_line, line));
	// if (printf("texture count {%d}\n", texture_count) && texture_count <= 5 && processed_line[0] != '1')
	// {
	// 	return (free(processed_line), EXIT_FAILURE);
	// }
	// else
	// 	return (update_map(game, processed_line, line));
	return (free(processed_line), EXIT_SUCCESS);
}

int	extractfile(t_soul_catcher *game, int fd)
{
	char		*line;
	static char	*t_ids[7] = {"NO", "EA", "WE", "SO", "F", "C", NULL};

	line = get_next_line(fd);
	if (!line)
		return (perr("empty map lol", 13), 13);
	while (line)
	{
		if (line[0] || line[0] == '\n')
		{
			if (set_game_data(game, line, t_ids))
				return (free(line), EXIT_FAILURE);
			free(line);
			line = ft_strdup("");
		}
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	return (free(line), EXIT_SUCCESS);
}

