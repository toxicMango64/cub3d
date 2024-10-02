/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:03:15 by mlumibao          #+#    #+#             */
/*   Updated: 2024/10/02 21:25:43 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	xpm_img(t_soul_catcher *game)
{
	game->north.ptr = mlx_xpm_file_to_image(game->p_mlx, \
	game->textures->north, &game->north.width, &game->north.height);
	if (!game->north.ptr)
	{
		exit_init(game, "Can't initialize XPM file");
	}
	game->south.ptr = mlx_xpm_file_to_image(game->p_mlx, \
	game->textures->south, &game->south.width, &game->south.height);
	if (!game->south.ptr)
		exit_init(game, "Can't initialize XPM file");
	game->east.ptr = mlx_xpm_file_to_image(game->p_mlx, \
	game->textures->east, &game->east.width, &game->east.height);
	if (!game->east.ptr)
		exit_init(game, "Can't initialize XPM file");
	game->west.ptr = mlx_xpm_file_to_image(game->p_mlx, \
	game->textures->west, &game->west.width, &game->west.height);
	if (!game->west.ptr)
		exit_init(game, "Can't initialize XPM file");
}

void	init_tex_adr(t_soul_catcher *game)
{
	game->north.adr = mlx_get_data_addr(game->north.ptr, \
	&game->north.bpp, &game->north.len, &game->north.endian);
	if (!game->north.adr)
		return (exit_init(game, "Can't get data address"));
	game->south.adr = mlx_get_data_addr(game->south.ptr, \
	&game->south.bpp, &game->south.len, &game->south.endian);
	if (!game->south.adr)
		return (exit_init(game, "Can't get data address"));
	game->east.adr = mlx_get_data_addr(game->east.ptr, \
	&game->east.bpp, &game->east.len, &game->east.endian);
	if (!game->east.adr)
		return (exit_init(game, "Can't get data address"));
	game->west.adr = mlx_get_data_addr(game->west.ptr, \
	&game->west.bpp, &game->west.len, &game->west.endian);
	if (!game->west.adr)
		return (exit_init(game, "Can't get data address"));
}

void	init_xpm(t_soul_catcher *game)
{
	xpm_img(game);
	init_tex_adr(game);
}
