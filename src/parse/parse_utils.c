#include "cub3d.h"

// int	set_game_data(t_soul_catcher *game, char *line, char **t_ids)
// {
// 	int		i;
// 	char	*processed_line;

// 	processed_line = ft_strtrim(line, WHITESPACE);
// 	if (processed_line[0] == '1')
// 		return (append_map_content(game, processed_line, line));
// 	i = -1;
// 	while (t_ids[++i])
// 	{
// 		if (!ft_strncmp(processed_line, t_ids[i], ft_strlen(t_ids[i])))
// 		{
// 			if (game->map->full)
// 				return (free_textures(game->textures), free(processed_line), \
// 					ft_err("Misplaced texture path found."));
// 			if (assign_texture(i, processed_line + ft_strlen(t_ids[i]), \
// 				game) == EXIT_FAILURE)
// 				return (free_textures(game->textures), \
// 					free(processed_line), EXIT_FAILURE);
// 			break ;
// 		}
// 	}
// 	return (free(processed_line), EXIT_SUCCESS);
// }
