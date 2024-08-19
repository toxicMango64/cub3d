#include "../zlibc/libft.h"
#include "../utils/utils.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

# define UC char
# define F	"F"
# define C	"C"
# define NO	"NO"
# define SO	"SO"
# define WE	"WE"
# define EA	"EA"

# define WHITESPACES	" \v\t\f\r\n"

typedef struct	s_colorscheme	t_colorscheme;

struct s_colorscheme
{
	char *f; /* Floor color */
	char *c; /* Ceiling color */
	char *no; /* North wall color */
	char *ea; /* East wall color */
	char *we; /* West wall color */
	char *so; /* South wall color */
};

void	is_map_(char *line)
{
	static ssize_t	offset = 0;
	static char		**map_grid = NULL;
	static ssize_t	capacity = 0;
	char **new_map_grid = NULL;
	ssize_t i = -1;

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

int	read_color_scheme(t_colorscheme *scheme, int fd)
{
	char	*line;

	line = ft_strtrim(get_next_line(fd), WHITESPACES);
	while (line)
	{
		if (strncmp(line, "NO", strlen("NO")) == 0 && printf("NO: %s", line))
			scheme->no = ft_strtrim(line, "NO ");
		else if (strncmp(line, "EA", strlen("EA")) == 0 && printf("EA: %s", line))
			scheme->ea = ft_strtrim(line, "EA ");
		else if (strncmp(line, "WE", strlen("WE")) == 0 && printf("WE: %s", line))
			scheme->we = ft_strtrim(line, "WE ");
		else if (strncmp(line, "SO", strlen("SO")) == 0 && printf("SO: %s", line))
			scheme->so = ft_strtrim(line, "SO ");
		else if (strncmp(line, "F", strlen("F")) == 0 && printf("F: %s", line))
			scheme->f = ft_strtrim(line, "F ");
		else if (strncmp(line, "C", strlen("C")) == 0 && printf("C: %s", line))
			scheme->c = ft_strtrim(line, "C ");
		else if ('\0' != line[0] && '\n' != line[0])
			is_map_(line);
		free (line);
		line = get_next_line(fd);
	}
	return (0);
}

int main(int ac, char **av)
{
	int				fd;
	char			*filename;
	t_colorscheme	scheme;

	filename = av[1];
	fd = open(filename, O_RDONLY);
	if (!fd)
		return (printf("Error opening fd: {%s}\n", filename), 1);
	read_color_scheme(&scheme, fd);

	printf("/* --------------------------------------------------------- */\n");
	printf("F: {%s}\n", scheme.f);
	printf("C: {%s}\n", scheme.c);
	printf("NO: {%s}\n", scheme.no);
	printf("EA: {%s}\n", scheme.ea);
	printf("WE: {%s}\n", scheme.we);
	printf("SO: {%s}\n", scheme.so);
	printf("/* --------------------------------------------------------- */\n");

	return 0;
}
