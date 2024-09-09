#include "test.h"
#include "../zlibc/libft.h"
#include "../utils/utils.h"

void	print_file(t_list *file)
{
	t_list	*current;
	size_t	i	= -1;

	current = file;
	while (current != NULL)
	{
		printf("file{%zu}:\t{%s}\n", ++i, ft_strtrim(current->content, "\n"));
		current = current->next;
	}
	printf("file{%zu}:\t{%s}\n", i, "<<<<<<<<<<EOF>>>>>>>>>>");
}

// Function to read entire file line by line
void	read_file(t_list **file, int fd)
{
	char	*line;

	line = ft_strtrim(get_next_line(fd), "\n");
	while (line)
	{
		if (line[0])
			ft_lstadd_back(file, ft_lstnew(strdup(line)));
		free (line);
		line = ft_strtrim(get_next_line(fd), "\n");
	}
}

int main(int ac, char **av)
{
	int		fd;
	t_list	*file;

	if (2 != ac)
	file = NULL;
	fd = open(av[1], O_RDONLY);
	if (-1 == fd)
		return (printf("Error opening fd: {%s}\n", av[1]), 1);
	(read_file(&file, fd), close(fd));
	print_file(file);
	return (0);
}

void	extractfile(t_soul_catcher *game, t_list **file, int fd)
{
	char	*line;

	(void)game;
	line = ft_strtrim(get_next_line(fd), "\n");
	// intit_texture(game->map->texture);
	intit_texture();
	while (line)
	{
		if (line[0] && validline(line) == 0)
			ft_lstadd_back(file, ft_lstnew(ft_strdup(line)));
		free (line);
		line = ft_strtrim(get_next_line(fd), "\n");
	}
}

void	validate_map(char *path_to_map, t_soul_catcher *game)
{
	int	fd;

	map_signature_check(path_to_map);
	fd = open(path_to_map, O_RDONLY);
	(extractfile(game, &game->file, fd), close(fd));
	printconent(game);
}


// void	read_file(t_list *file, int fd)
// {
// 	char	*line;
// 	t_list	*current;
// 	t_list	*newnode;

// 	line = ft_strtrim(get_next_line(fd), "\n");
// 	current = file;
// 	while (line)
// 	{
// 		newnode = ft_lstnew(strdup(line));
// 		printf ("newnode {%s}\n", newnode->content);
// 		ft_lstadd_back(&current, newnode);
// 		// ft_lstadd_back(&current, ft_lstnew(strdup(line)));
// 		free (line);
// 		line = ft_strtrim(get_next_line(fd), "\n");
// 	}
// }

