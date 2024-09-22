/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:58:56 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/23 01:20:26 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "debug.h"

int	validate(const int ac, const char *const *av)
{
	if (ac != 2)
		return (printf("Usage: %s <map_file>\n", av[0]), 1);
	if (map_signature_check(av[1]))
		exit (-1);
	return (EXIT_SUCCESS);
}

int	close_x(t_soul_catcher *game)
{
	mlx_destroy_window(game->p_mlx, game->p_win);
	free(game->p_mlx);
	printf("<<<<<<HERE>>>>>>\n");
	// close_free(game);
	exit(0);
	return (0);
}

void	gfx_setup(t_soul_catcher *game)
{
	game->p_mlx = mlx_init();
	game->p_win = mlx_new_window(game->p_mlx, 1280, 720, "cub3D");
	printf("<<<<<<HERE>>>>>>\n");
	mlx_hook(game->p_win, 17, 0, close_x, &game);
	mlx_hook(game->p_win, 17, 1L << 2, handle_destroy, &game);
	mlx_hook(game->p_win, 2, 1L << 0, handle_keypress, &game);
	mlx_loop(game->p_mlx);
}

int	main(const int ac, const char *const *av)
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
