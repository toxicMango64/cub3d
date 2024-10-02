/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:26:48 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 21:31:02 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# include "../zlibc/libft.h"
# include "cub3d.h"
# include "struct.h"

void	calculate_ray(t_soul_catcher *game);

/* gfx_cleanup.c */
void	exit_init(t_soul_catcher *game, char *str);
int		close_game(t_soul_catcher *game);

/* init_gfx.c */
void	init_gfx(t_soul_catcher *game);

/* gfx_init_utils.c */
void	fill_map(t_soul_catcher *game, char **tmp, int len);
void	tab_space(char **map);
void	init_ray(t_ray *ray);

/* init_xpm.c */
void	init_xpm(t_soul_catcher *game);

/* direction.c */
void	get_direction(t_soul_catcher *game);

/* direction.c */
void	calculate_ray(t_soul_catcher *game);

/* draw_utils.c */
void	init_draw(t_draw *draw);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

/* gfx_utils.c */
int		color_convert(int *i);

/* draw_wall.c */
void	draw_wall(t_soul_catcher *game, t_draw *draw, int i);

/* keymap.c */
int		key_move(int keycode, t_soul_catcher *game);

/* movement.c */
void	move_w(t_soul_catcher *game);
void	move_s(t_soul_catcher *game);
void	move_a(t_soul_catcher *game);
void	move_d(t_soul_catcher *game);

/* wallcolli.c */
int		check_wall(t_soul_catcher *game, double x, double y);
int		check_move(t_soul_catcher *game, double x, double y);

#endif
