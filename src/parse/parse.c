/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:38:06 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/19 06:10:07 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// tar: Error opening archive: Error reading 'maps'
void	map_signature_check(const char *path_to_map)
{
	int		fd;
	ssize_t	offset;

	offset = 0;
	while (path_to_map[offset] != '\0')
		offset++;
	if (strcmp_sst(path_to_map, ".cub", offset - 4) != 0)
		perr ("cub3d: unknown suffix -- ignored", 2);
	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		perr ("cub3d: Error opening file: Error reading 'map'", -1);
	close(fd);
}

int	extractfile(t_soul_catcher *game, int fd)
{
	(void)game;
	(void)fd;
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
		if (printf("line: {%s}\n", line) && (line[0] || line[0] != '\n'))
		{
			if (set_game_data(game, line, t_ids))
				return (free(line), EXIT_FAILURE);
			free(line);
			line = ft_strdup("");
		}
	}
	return (free(line), EXIT_SUCCESS);
}

int	validate_map(const char *path_to_map, t_soul_catcher *game)
{
	int	fd;

	(void)game;
	map_signature_check(path_to_map);
	fd = open(path_to_map, O_RDONLY);
	(extractfile(game, fd), close(fd));

	printconent(game);
	return (EXIT_SUCCESS);
}
