#include "test.h"
#include "../zlibc/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	set_game_data(char *line, t_data *data)
{
	int		i;
	char	*processed_line;
	char	*t_ids[7];

	set_texture_ids(t_ids);
	processed_line = ft_strtrim(line, WHITESPACE);
	if (processed_line[0] == '1')
		return (append_map_content(data, processed_line, line));
	i = -1;
	while (t_ids[++i])
	{
		if (!ft_strncmp(processed_line, t_ids[i], ft_strlen(t_ids[i])))
		{
			if (data->map->full)
				return (free_textures(data->textures), free(processed_line), \
					ft_err("Misplaced texture path found."));
			if (assign_texture(i, processed_line + ft_strlen(t_ids[i]), \
				data) == EXIT_FAILURE)
				return (free_textures(data->textures), \
					free(processed_line), EXIT_FAILURE);
			break ;
		}
	}
	return (free(processed_line), EXIT_SUCCESS);
}

/**
 * @brief Read the map in the data struct character by character and check for 
 * newlines. Once found, send the full line to the `set_game_data` function
 * which sets the appropriate structs in the data struct.
 * 
 * @param data 
 */
int	process_map(t_data *data)
{
	char	*line;
	char	read_buffer[2];
	char	*temp;
	int		output;

	line = ft_strdup("");
	output = 1;
	while (output)
	{
		output = read(data->map->fd, read_buffer, 1);
		if (!output)
			break ;
		read_buffer[output] = '\0';
		temp = line;
		line = ft_strjoin(line, read_buffer);
		free(temp);
		if (read_buffer[0] == '\n')
		{
			if (set_game_data(line, data) == EXIT_FAILURE)
				return (free(line), EXIT_FAILURE);
			free(line);
			line = ft_strdup("");
		}
	}
	return (free(line), EXIT_SUCCESS);
}
