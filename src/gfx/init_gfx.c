/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:58:56 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 21:22:49 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static int	find_row_len(char **map)
{
	int		i;
	int		res;
	int		j;
	char	*ptr;

	i = -1;
	res = 0;
	ptr = NULL;
	while (map[++i])
	{
		j = 0;
		ptr = ft_strrchr(map[i], '1');
		if (ptr)
		{
			while (&map[i][j] != ptr)
				j++;
			if (++j > res)
				res = j;
		}
	}
	return (res);
}

void	rect_map(t_soul_catcher *game)
{
	char	**tmp;

	tmp = malloc(sizeof (char *) * (arr_size(game->map->grid) + 1));
	fill_map(game, tmp, find_row_len(game->map->grid));
	tab_space(game->map->grid);
	game->map->height = arr_size(game->map->grid);
	game->map->width = find_row_len(game->map->grid);
}

void	init_mlx(t_soul_catcher *game)
{
	game->p_mlx = mlx_init();
	if (!game->p_mlx)
		exit_init(game, "Error: Can't initialize mlx\n");
	init_xpm(game);
	game->p_win = mlx_new_window(game->p_mlx, GAMEWIDTH, GAMEHEIGHT, "cub3D");
	if (!game->p_win)
		exit_init(game, "Error: Can't initialize mlx\n");
	game->frame.ptr = mlx_new_image(game->p_mlx, GAMEWIDTH, GAMEHEIGHT);
	if (!game->frame.ptr)
		exit_init(game, "Error: Can't initialize buffer\n");
	game->frame.adr = mlx_get_data_addr(game->frame.ptr, \
	&game->frame.bpp, &game->frame.len, &game->frame.endian);
	if (!game->frame.adr)
		exit_init(game, "Error: Can't initialize buffer\n");
}

void	init_player(t_soul_catcher *game)
{
	game->player->pos_x = game->player_pos->spawn_y + 0.5;
	game->player->pos_y = game->player_pos->spawn_x + 0.5;
	game->player->facing = game->player_pos->direction;
	get_direction(game);
}

void	init_gfx(t_soul_catcher *game)
{
	rect_map(game);
	init_mlx(game);
	game->player = malloc(sizeof(t_player));
	init_player(game);
	game->ray = malloc(sizeof(t_ray));
	init_ray(game->ray);
	game->draw_flag = 1;
}
