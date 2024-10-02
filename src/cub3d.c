/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:58:56 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 17:37:09 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "debug.h"

int	validate(const int ac, const char *const *av)
{
	if (ac != 2)
		return (perr("Usage: %s <input map file>", av[0]));
	if (file_signature_check(MAP, av[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
	print_info(game->textures, game->map);
	// exec_game(game);
	return (EXIT_SUCCESS);
}
