/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:58:56 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/21 23:17:12 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "debug.h"

void	gfx_setup(t_soul_catcher *game)
{
	game->p_mlx = mlx_init();
	game->p_win = mlx_new_window(game->p_mlx, 1280, 720, "cub3D");
	mlx_hook(game->p_win, 17, 1L << 2, handle_destroy, &game);
	mlx_hook(game->p_win, 2, 1L << 0, handle_keypress, &game);
	mlx_loop(game->p_mlx);
}

int	validate(const int ac, const char * const *av)
{
	if (ac != 2)
		return (printf("Usage: %s <map_file>\n", av[0]), 1);
	if (map_signature_check(av[1]))
		exit (-1);
	return (EXIT_SUCCESS);
}

int	main(const int ac, const char * const *av)
{
	t_soul_catcher	game;
	t_map			map;
	t_point			player;
	t_textures		textures;

	if (validate(ac, av))
		return (EXIT_FAILURE);
	init_soul_catcher(&game, &player, &map, &textures);
	map.fd = open(av[1], O_RDONLY);
	if (extractfile(&game, map.fd))
		return (close(game.map->fd), EXIT_FAILURE);
	if (is_map_valid(&game))
		return (close(game.map->fd), free(game.map->full), \
			freearr(map.grid), free_textures(game.textures), EXIT_FAILURE);
	print_info(*game.textures, map);
	gfx_setup(&game);
	return (EXIT_SUCCESS);
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
