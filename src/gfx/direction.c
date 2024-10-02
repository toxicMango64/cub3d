/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:58:56 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 18:38:36 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	get_direction_2(t_soul_catcher *game)
{
	if (game->player->facing == 'E')
	{
		game->player->dir_x = 0;
		game->player->dir_y = 1;
		game->player->plane_x = 0.66;
		game->player->plane_y = 0;
	}
	else if (game->player->facing == 'W')
	{
		game->player->dir_x = 0;
		game->player->dir_y = -1;
		game->player->plane_x = -0.66;
		game->player->plane_y = 0;
	}
}

void	get_direction(t_soul_catcher *game)
{
	if (game->player->facing == 'S')
	{
		game->player->dir_x = 1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = -0.66;
	}
	else if (game->player->facing == 'N')
	{
		game->player->dir_x = -1;
		game->player->dir_y = 0;
		game->player->plane_x = 0;
		game->player->plane_y = 0.66;
	}
	else
		get_direction_2(game);
}
