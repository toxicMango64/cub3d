#include "../inc/cub3d.h"

int	parse(int ac, char **av, t_soul_catcher *game)
{
	if (ac != 2)
		return (printf("Usage: %s <map_file>\n", av[0]), 1);
	if (validate_map(av[1], game))
		return (EXIT_FAILURE);
	// find_valid_path(game);
	return (EXIT_SUCCESS);
}

int	main(const int ac, const char * const *av)
{
	t_soul_catcher	game;

	game.map = malloc(sizeof(t_map));
	if (initgame(ac, av, &game))
		return (EXIT_FAILURE);
	if (parse(ac, av, &game))
		return (EXIT_FAILURE);
	return (0);
}

/* -------------------------------------------------------------------------- */

// int	main(int ac, char **av)
// {
// 	int				error;
// 	t_soul_catcher	game;

// 	error = 0;
// 	game.map = malloc(sizeof(t_map));
// 	if (ac != 2)
// 		return (printf("Usage: %s <map_file>\n", av[0]), 1);
// 	parse(av[1], &game);
// 	game->map = parse(av[1], game);
// 	if (!game.map.grid)
// 		return (printf("Error parsing map file\n"), 1);
// 	init_cb3d(game);
// 	mlx_init(&game->window_width, &game->window_height, "cub3D", 0);
// 	while (1)
// 	{
// 		handle_events(&game);
// 		update_game_state(&game);
// 		render_frame(&game);
// 		usleep(16000);
// 	}
// 	free_map(&game->map);
// 	mlx_destroy_window();
// 	return (0);
// }

/* -------------------------------------------------------------------------- */
