#include "../inc/cub3d.h"

void	parse_map_file(char *path_to_map, t_soul_catcher *game)
{
	// read_map(game);
	validate_map(path_to_map, game);
	// find_valid_path(game);
}

int	main(int ac, char **av)
{
	int				error;
	t_soul_catcher	*game = NULL;

	error = 0;
	if (ac != 2)
		return (printf("Usage: cub3D <map_file>\n"), 1);
	parse_map_file(av[1], game);
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
