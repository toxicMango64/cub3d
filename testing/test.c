#include "test.h"
#include "../zlibc/libft.h"

char	**is_map_(char **map, char *line)
{
	ssize_t			i = -1;
	char 			**new_map_grid = NULL;
	static ssize_t	offset = 0;
	static ssize_t	capacity = 0;

	if (map == NULL)
	{
		capacity = 1;
		map = (char **) malloc(capacity * sizeof(char *));
		if (map == NULL)
			return (NULL);
	}
	if (offset >= capacity)
	{
		new_map_grid = (char **) malloc((capacity * 2) * sizeof(char *));
		if (new_map_grid == NULL)
			return (NULL);
		while (++i < offset)
		{
			new_map_grid[i] = map[i];
			free(map[i]);
		}
		map = new_map_grid;
		capacity *= 2;
	}
	map[offset] = line;
	printf("map grid: {%zi}\t%s", offset, map[offset]);
	offset++;
	return (map);
}

// void	is_map_(char **map, char *line)
// {
// 	ssize_t			i = -1;
// 	char 			**new_map_grid;
// 	static ssize_t	offset = 0;
// 	static ssize_t	capacity = 0;

// 	if (offset >= capacity)
// 	{
// 		new_map_grid = (char **) malloc((capacity * 2) * sizeof(char *));
// 		if (new_map_grid == NULL)
// 			return ;
// 		map[offset] = (char **) malloc(capacity * sizeof(char *));
// 		if (map[offset] == NULL)
// 			return ;
// 		while (++i < offset)
// 		{
// 			new_map_grid[i] = map[i];
// 			free(map[i]);
// 		}
// 		free(map);
// 		map[offset] = new_map_grid;
// 		capacity *= 2;
// 	}
// 	map[offset][offset] = line;
// 	printf("map grid: {%zi}\t%s", offset, map[offset][offset]);
// 	offset++;
// }

int	get_map_height(char *path_to_map, int fd)
{
	int		map_height;
	char	*map;

	map_height = 0;
	map = get_next_line(fd);
	if (map == NULL)
		perr ("empty map lol", 13);
	while (map)
	{
		free(map);
		map = get_next_line(fd);
		map_height++;
	}
	free(map);
	return (map_height);
}


// int	read_color_scheme(t_colorscheme *scheme, int fd)
// {
// 	char	*line;
// 	char	**map;

// 	line = ft_strtrim(get_next_line(fd), WHITESPACE);
// 	while (line)
// 	{
// 		if (strncmp(line, "NO", strlen("NO")) == 0 && printf("NO: %s", line))
// 			scheme->no = ft_strtrim(line, "NO ");
// 		else if (strncmp(line, "EA", strlen("EA")) == 0 && printf("EA: %s", line))
// 			scheme->ea = ft_strtrim(line, "EA ");
// 		else if (strncmp(line, "WE", strlen("WE")) == 0 && printf("WE: %s", line))
// 			scheme->we = ft_strtrim(line, "WE ");
// 		else if (strncmp(line, "SO", strlen("SO")) == 0 && printf("SO: %s", line))
// 			scheme->so = ft_strtrim(line, "SO ");
// 		else if (strncmp(line, "F", strlen("F")) == 0 && printf("F: %s", line))
// 			scheme->f = ft_strtrim(line, "F ");
// 		else if (strncmp(line, "C", strlen("C")) == 0 && printf("C: %s", line))
// 			scheme->c = ft_strtrim(line, "C ");
// 		else if ('\0' != line[0] && '\n' != line[0])
// 			map = is_map_(map, line);
// 		free (line);
// 		line = ft_strtrim(get_next_line(fd), WHITESPACE);
// 	}
// 	return (0);
// }

static t_texture	*cubnew(void *content)
{
	t_texture	*newnode;

	newnode = (t_texture *)malloc(sizeof(t_texture));
	if (!(newnode))
		return (NULL);
	newnode -> key = content;
	return (newnode);
}

int	read_color_scheme(t_texture *scheme, int fd)
{
	char		*line;
	char		**map;
	t_texture	*current;

	line = ft_strtrim(get_next_line(fd), WHITESPACE);
	while (line)
	{
		current = scheme;
		while (current != NULL)
		{
			if (!strncmp(line, current->key, strlen(current->key)))
				lstadd_back(scheme, cubnew(ft_strtrim(line, current->key)));
			current = current->next;
		}
		free (line);
		line = ft_strtrim(get_next_line(fd), WHITESPACE);
	}
	return (0);
}
// if ('\0' != line[0] && '\n' != line[0])
// 	map = is_map_(map, line);

int	read_color_scheme(t_texture *scheme, int fd)
{
	char		*line;
	char		**map;
	t_texture	*current;

	while ((line = ft_strtrim(get_next_line(fd), WHITESPACE)) != NULL)
	{
		current = scheme;
		while (current != NULL)
		{
			if (!strncmp(line, current->key, strlen(current->key)))
			{
				current->file = ft_strtrim(line + strlen(current->key), WHITESPACE);
				break;
			}
			current = current->next;
		}
		if ('\0' != line[0] && '\n' != line[0])
			map = is_map_(map, line);
		free(line);
	}
	return (0);
}

void	parse_lines(t_texture **list, char *line)
{
    t_texture	*current;

	current = *list;
    while (current != NULL)
	{
        if (strncmp(current->key, line, strlen(current->key)) == 0)
		{
            current->file = strdup(line + strlen(current->key));
            break ;
        }
        current = current->next;
    }
    if (current == NULL)
	{
        current = malloc(sizeof(t_texture));
        current->key = strdup(line);
        current->file = NULL;
        current->next = *list;
        *list = current;
    }
}

// int main(int ac, char **av)
// {
// 	int				fd;
// 	char			*filename;
// 	// t_colorscheme	scheme;
// 	t_texture		*texturefile;

// 	filename = av[1];
// 	fd = open(filename, O_RDONLY);
// 	if (!fd)
// 		return (printf("Error opening fd: {%s}\n", filename), 1);
// 	texturefile = NULL;
// 	texturefile = intit_texture(&texturefile);	
// 	read_color_scheme(texturefile, fd);

// 	// printf("/* --------------------------------------------------------- */\n");
// 	// printf("F: {%s}\n", scheme.f);
// 	// printf("C: {%s}\n", scheme.c);
// 	// printf("NO: {%s}\n", scheme.no);
// 	// printf("EA: {%s}\n", scheme.ea);
// 	// printf("WE: {%s}\n", scheme.we);
// 	// printf("SO: {%s}\n", scheme.so);
// 	// printf("/* --------------------------------------------------------- */\n");

// 	return 0;
// }
