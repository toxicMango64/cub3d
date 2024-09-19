/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:58:58 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/19 05:59:59 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/debug.h"

int		wrerr(const char *str)
{
	while (str)
		write(2, str++, 1);
	return (EXIT_FAILURE);
}

int		wr(const char *str)
{
	while (str)
		write(2, str++, 1);
	return (EXIT_SUCCESS);
}

void	printconent(t_soul_catcher *game)
{
	puts("Texture Paths: ");
	if (game->textures->north)
		(printf("North texture: "), puts(game->textures->north));
	if (game->textures->east)
		(printf("East texture: "), puts(game->textures->east));
	if (game->textures->west)
		(printf("West texture: "), puts(game->textures->west));
	if (game->textures->south)
		(printf("South texture: "), puts(game->textures->south));
	if (game->textures->floor)
		(printf("Floor texture: "), puts(game->textures->floor));
	if (game->textures->ceiling)
		(printf("Ceiling texture: "), puts(game->textures->ceiling));
	if (game->map->full)
		(puts("\nMap: "), puts(game->map->full));
}
