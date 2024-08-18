#include "../../inc/cub3d.h"

void	game_signature_check(char *path_to_map)
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
	ft_printf("{%s}\n", path_to_map);
	ft_printf("{%s}\n", path_to_map);
}

void	validate_map(char *path_to_map, t_soul_catcher *game)
{
	// int	fd;

	(void)game;
	game_signature_check(path_to_map);
	// fd = open(path_to_map, O_RDONLY);
	// game->height = get_map_height(path_to_map);
	// close(fd);
	// fd = open(path_to_map, O_RDONLY);
	// get_map(fd, game);
	// close(fd);
	// game->width = ft_stlen(game->map[0]);
	// if (game->width > 43)
	// {
	// 	free_char_arr(game->map, game->height);
	// 	free_char_arr(game->temp_map, game->height);
	// 	perr ("Map not valid", 5);
	// }
}

/* -------------------------------------------------------------------------- */

// t_map	parse_map_file(char *filename)
// {
// 	t_map	*map;
// 	// FILE	*file = fopen(filename, "r");
// 	int		file = open(filename, "r");
// 	char	line[1024];

// 	while (fgets(line, 1024, file))
// 	{
// 		if (line[0] == '1' || line[0] == '0' || line[0] == 'N' || line[0] == 'S'
// 			|| line[0] == 'E' || line[0] == 'W')
// 		{
// 			map->grid = parse_map_grid(line, &map->width, &map->height);
// 			if (!map->grid)
// 				return (printf("Error parsing map grid\n"), (t_map){0});
// 		}
// 		else if (strncmp(line, "NO ", 3) == 0)
// 			map->north_texture = parse_texture(line);
// 		else if (strncmp(line, "SO ", 3) == 0)
// 			map->south_texture = parse_texture(line);
// 		else if (strncmp(line, "WE ", 3) == 0)
// 			map->west_texture = parse_texture(line);
// 		else if (strncmp(line, "EA ", 3) == 0)
// 			map->east_texture = parse_texture(line);
// 		else if (strncmp(line, "F ", 2) == 0)
// 			map->floor_color = parse_color(line);
// 		else if (strncmp(line, "C ", 2) == 0)
// 			map->ceiling_color = parse_color(line);
// 	}
// 	return (close(file), map);
// }

// void handle_events(t_soul_catcher *game)
// {
// 	int	mouse_x;
// 	int	mouse_y;

// 	if (mlx_is_key_down(MLX_KEY_W))
// 		game->move_forward = 1;
// 	if (mlx_is_key_down(MLX_KEY_S))
// 		game->move_backward = 1;
// 	if (mlx_is_key_down(MLX_KEY_A))
// 		game->turn_left = 1;
// 	if (mlx_is_key_down(MLX_KEY_D))
// 		game->turn_right = 1;
// 	if (mlx_is_key_down(MLX_KEY_ESC))
// 		exit(0);
// 	mlx_get_mouse_pos(&mouse_x, &mouse_y);
// 	game->mouse_x = mouse_x;
// 	game->mouse_y = mouse_y;
// 	if (mlx_is_mouse_down(MLX_MOUSE_BUTTON_LEFT))
// 		game->turn_left = 1;
// 	if (mlx_is_mouse_down(MLX_MOUSE_BUTTON_RIGHT))
// 		game->turn_right = 1;
// 	if (mlx_is_window_resized())
// 	{
// 		game->window_width = mlx_get_window_width();
// 		game->window_height = mlx_get_window_height();
// 	}
// 	if (mlx_is_window_closed())
// 		exit(0);
// }
