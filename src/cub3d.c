#include "../inc/cub3d.h"

void	parse_map_file(char *path_to_map, t_soul_catcher *game)
{
	validate_map(path_to_map, game);
	// read_map(game);
	// find_valid_path(game);
}

int	main(int ac, char **av)
{
	int				error;
	t_soul_catcher	game;

	error = 0;
	game.scheme = malloc(sizeof(t_colorscheme));
	game.map = malloc(sizeof(t_map));
	if (ac != 2)
		return (printf("Usage: cub3D <map_file>\n"), 1);
	parse_map_file(av[1], &game);
	// game->map = parse_map_file(av[1], game);
	// if (!game.map.grid)
	// 	return (printf("Error parsing map file\n"), 1);
	// init_cb3d(game);
	// mlx_init(&game->window_width, &game->window_height, "cub3D", 0);
	// while (1)
	// {
	// 	handle_events(&game);
	// 	update_game_state(&game);
	// 	render_frame(&game);
	// 	usleep(16000);
	// }
	// free_map(&game->map);
	// mlx_destroy_window();
	return (0);
}

/* -------------------------------------------------------------------------- */

// int	parse_map_file(t_map *map, int fd)
// {
// 	char	*line;

// 	line = ft_strtrim(get_next_line(fd), WHITESPACES);
// 	while (fgets(line, 1024, fd))
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
// 	return (close(fd), 0);
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

/* -------------------------------------------------------------------------- */
