#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	map_signature_check(char *path_to_map)
{
	int		fd;
	ssize_t	offset;

	offset = 0;
	while ('\0' != path_to_map[offset] && printf("path_to_map: {%c}\n", path_to_map[offset]))
		offset++;
	if (strncmp(path_to_map + offset - 4, ".cub", 4))
		return (printf("cub3d: unknown suffix -- ignored"));
	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		return (printf("open: fd is not valid"));
	close(fd);
	return (0);
}

int main(int ac, char **av)
{
	if (2 > ac)
		return (EXIT_FAILURE);
	if (map_signature_check(av[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
