/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:58:56 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/05 12:24:36 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
#include "cub3d.h"

void	draw_ray(t_soul_catcher *game, t_draw *draw, int i)
{
	int	y;

	y = 0;
	while (y < draw->draw_start)
	{
		my_mlx_pixel_put(&game->frame, i, y, \
			color_convert(game->map->ceiling_color));
		y++;
	}
	draw_wall(game, draw, i);
	y = draw->draw_end;
	while (y < GAMEHEIGHT - 1)
	{
		my_mlx_pixel_put(&game->frame, i, y, \
			color_convert(game->map->floor_color));
		y++;
	}
}

void	calculate_step(t_soul_catcher *game)
{
	if (game->ray->ray_dir_x < 0)
	{
		game->ray->step_x = -1;
		game->ray->side_dist_x = (game->player->pos_x - game->ray->map_x) \
		* game->ray->delta_dist_x;
	}
	else
	{
		game->ray->step_x = 1;
		game->ray->side_dist_x = (game->ray->map_x + 1.0 - game->player->pos_x) \
		* game->ray->delta_dist_x;
	}
	if (game->ray->ray_dir_y < 0)
	{
		game->ray->step_y = -1;
		game->ray->side_dist_y = (game->player->pos_y - game->ray->map_y) \
		* game->ray->delta_dist_y;
	}
	else
	{
		game->ray->step_y = 1;
		game->ray->side_dist_y = (game->ray->map_y + 1.0 - game->player->pos_y) \
		* game->ray->delta_dist_y;
	}
}

void	dda(t_soul_catcher *game)
{
	while (game->ray->hit == 0)
	{
		if (game->ray->side_dist_x < game->ray->side_dist_y)
		{
			game->ray->side_dist_x += game->ray->delta_dist_x;
			game->ray->map_x += game->ray->step_x;
			game->ray->side = 0;
		}
		else
		{
			game->ray->side_dist_y += game->ray->delta_dist_y;
			game->ray->map_y += game->ray->step_y;
			game->ray->side = 1;
		}
		if (game->map->grid[game->ray->map_x][game->ray->map_y] == '1')
			game->ray->hit = 1;
	}
}

void	perp(t_soul_catcher *game, int i)
{
	t_draw	draw;

	init_draw(&draw);
	if (game->ray->side == 0)
		game->ray->perp_wall_dist = (game->ray->side_dist_x \
		- game->ray->delta_dist_x);
	else
		game->ray->perp_wall_dist = (game->ray->side_dist_y \
		- game->ray->delta_dist_y);
	draw.line_h = (int)(GAMEHEIGHT / game->ray->perp_wall_dist);
	draw.draw_start = -draw.line_h / 2 + GAMEHEIGHT / 2;
	if (draw.draw_start < 0)
		draw.draw_start = 0;
	draw.draw_end = draw.line_h / 2 + GAMEHEIGHT / 2;
	if (draw.draw_end >= GAMEHEIGHT)
		draw.draw_end = GAMEHEIGHT - 1;
	if (game->ray->side == 0)
		draw.wall_x = game->player->pos_y + game->ray->perp_wall_dist \
		* game->ray->ray_dir_y;
	else
		draw.wall_x = game->player->pos_x + game->ray->perp_wall_dist \
		* game->ray->ray_dir_x;
	draw.wall_x -= floor(draw.wall_x);
	draw_ray(game, &draw, i);
}

void	calculate_ray(t_soul_catcher *game)
{
	int		i;

	i = 0;
	mlx_clear_window(game->p_mlx, game->p_win);
	while (i < GAMEWIDTH)
	{
		init_ray(game->ray);
		game->ray->camera_x = 2 * i / (double)GAMEWIDTH - 1;
		game->ray->ray_dir_x = game->player->dir_x + game->player->plane_x \
		* game->ray->camera_x;
		game->ray->ray_dir_y = game->player->dir_y + game->player->plane_y \
		* game->ray->camera_x;
		game->ray->map_x = game->player->pos_x;
		game->ray->map_y = game->player->pos_y;
		game->ray->delta_dist_x = fabs(1 / game->ray->ray_dir_x);
		game->ray->delta_dist_y = fabs(1 / game->ray->ray_dir_y);
		calculate_step(game);
		dda(game);
		perp(game, i);
		i++;
	}
	mlx_put_image_to_window(game->p_mlx, game->p_win, \
	game->frame.ptr, 0, 0);
	game->draw_flag = 0;
}
