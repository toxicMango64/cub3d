#include "../../inc/cub3d.h"

void	map_signature_check(char *path_to_map)
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
		perr ("open: fd is not valid", -1);
	close(fd);
}

void	is_map(char **map_grid, char *line)
{
	ssize_t			i = -1;
	static ssize_t	offset;
	static ssize_t	capacity;
	char			**new_map_grid;

	if (map_grid == NULL)
	{
		capacity = 1;
		map_grid = (char **) malloc(capacity * sizeof(char *));
		if (map_grid == NULL)
			return ;
	}
	if (offset >= capacity)
	{
		new_map_grid = (char **) malloc((capacity * 2) * sizeof(char *));
		if (new_map_grid == NULL)
			return ;
		while (++i < offset)
			new_map_grid[i] = map_grid[i];
		free(map_grid);
		map_grid = new_map_grid;
		capacity *= 2;
	}
	map_grid[offset] = line;
	printf("map grid: {%zi}\t%s", offset, map_grid[offset]);
	offset++;
}

void	read_color_scheme(t_colorscheme *scheme, char **grid, int fd)
{
	char			*line;

	line = ft_strtrim(get_next_line(fd), WHITESPACES);
	while (line && printf("while loop: {%s}\n", line)) // remove debug printf
	{
		if (strncmp(line, "NO", strlen("NO")) == 0)
			scheme->no = ft_strtrim(line, "NO ");
		else if (strncmp(line, "EA", strlen("EA")) == 0)
			scheme->ea = ft_strtrim(line, "EA ");
		else if (strncmp(line, "WE", strlen("WE")) == 0)
			scheme->we = ft_strtrim(line, "WE ");
		else if (strncmp(line, "SO", strlen("SO")) == 0)
			scheme->so = ft_strtrim(line, "SO ");
		else if (strncmp(line, "F", strlen("F")) == 0)
			scheme->f = ft_strtrim(line, "F ");
		else if (strncmp(line, "C", strlen("C")) == 0)
			scheme->c = ft_strtrim(line, "C ");
		else if (line[0] && !strpbrk(line, WHITESPACES))
			is_map(grid, line);
		free (line);

		line = get_next_line(fd);
		while (!strpbrk(line, WHITESPACES))
		{
			free (line);
			line = get_next_line(fd);
			printf("strpbrk line: {%s}\n\n", line);
		}
		line = ft_strtrim(line, WHITESPACES);
	}
}

void	validate_map(char *path_to_map, t_soul_catcher *game)
{
	int	fd;

	map_signature_check(path_to_map);
	fd = open(path_to_map, O_RDONLY);
	if (fd == -1)
		perr ("open: fd is not valid", -1);
	read_color_scheme(game->scheme, game->map->grid, fd);
	close(fd);
}
