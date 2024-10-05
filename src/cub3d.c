/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:58:56 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/05 12:27:49 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate(const int ac, const char *const *av)
{
	if (ac != 2)
		return (perr("Usage: %s <input map file>", av[0]));
	if (file_signature_check(MAP, av[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	game_loop(t_soul_catcher *game)
{
	if (game->draw_flag == 0)
		return (0);
	calculate_ray(game);
	return (1);
}

void	exec_game(t_soul_catcher *game)
{
	init_gfx(game);
	game->draw_flag = 1;
	mlx_loop_hook(game->p_mlx, game_loop, game);
	mlx_hook(game->p_win, 2, 1L << 0, key_move, game);
	mlx_hook(game->p_win, 17, 1L << 17, close_game, game);
	mlx_loop(game->p_mlx);
}

int	main(const int ac, const char *const *av)
{
	t_soul_catcher	*game;
	char			*line;

	if (validate(ac, av))
		return (EXIT_FAILURE);
	game = ft_calloc(1, sizeof(t_soul_catcher));
	if (!game || init_soul_catcher(game))
		return (perr("Cub3d: Could not initialize game"), EXIT_FAILURE);
	game->map->fd = open(av[1], O_RDONLY);
	line = get_next_line(game->map->fd);
	if (!line)
		return (perr("empty map lol"));
	if (extractfile(game, line, game->map->fd))
		return (free_soul_catcher(game), EXIT_FAILURE);
	if (is_map_valid(game))
		return (free_soul_catcher(game), EXIT_FAILURE);
	exec_game(game);
	return (EXIT_SUCCESS);
}
