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

// void	extractfile(t_soul_catcher *game, int fd)
// {
// 	char	*line;
// 	char	*t_ids[7];

// 	set_texture_ids(t_ids);
// 	line = ft_strdup("");
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		if (line[0] && line[0] != '\n')
// 		{
// 			if (set_game_data(line, game, t_ids))
// 				return (free(line), EXIT_FAILURE);
// 			free(line);
// 			line = ft_strdup("");
// 		}
// 	}
// 	return (EXIT_SUCCESS);
// }

int	validate_map(const char *path_to_map, t_soul_catcher *game)
{
	int	fd;

	(void)game;
	map_signature_check(path_to_map);
	fd = open(path_to_map, O_RDONLY);
	close(fd);
	// (extractfile(game, fd), close(fd));
	// printconent(game);
	return (EXIT_SUCCESS);
}
