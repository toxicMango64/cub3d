/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:58:56 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 18:59:46 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	fill_map(t_soul_catcher *game, char **tmp, int len)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		tmp[i] = malloc(sizeof(char) * (len + 1));
		if (!tmp[i])
			return ;
		j = -1;
		while (game->map->grid[i][++j])
			tmp[i][j] = game->map->grid[i][j];
		while (j < len)
		{
			tmp[i][j] = '1';
			j++;
		}
		tmp[i][j] = '\0';
		i++;
	}
	tmp[i] = NULL;
	freearr(game->map->grid);
	game->map->grid = tmp;
}

void	tab_space(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '\t')
				map[i][j] = ' ';
		}
	}
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->perp_wall_dist = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
}
