#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int fd;
	char *path_to_map = av[1];

	fd = open(path_to_map, O_RDONLY);
	if (-1 == fd)
		return (perror("open: "), -1);
	return (0);
}
