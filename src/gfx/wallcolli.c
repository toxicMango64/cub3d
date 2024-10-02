/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcolli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:58:56 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 19:07:45 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_wall(t_soul_catcher *game, double x, double y)
{
	if (game->map->grid[(int)x][(int)y]
		&& game->map->grid[(int)x][(int)y] == '0')
		return (TRUE);
	return (FALSE);
}

int	check_move(t_soul_catcher *game, double x, double y)
{
	int		i;

	i = 0;
	if (check_wall(game, x, game->player->pos_y))
	{
		game->player->pos_x = x;
		i = 1;
	}
	if (check_wall(game, game->player->pos_x, y))
	{
		game->player->pos_y = y;
		i = 1;
	}
	return (i);
}
