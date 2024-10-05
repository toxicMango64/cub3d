/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosman <nosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:51:08 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/05 12:26:14 by nosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define TRUE 1
# define FALSE 0

# define WHITESPACE	" \v\t\f\r\n"
# define FOPEN	"Error opening file: Failed to open"
# define GAMEWIDTH	1280
# define GAMEHEIGHT	720
# define F	4
# define C	5

// mlx/gfx
# include <../opengl/mlx.h>
# include <limits.h>
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define L 123
# define R 124
# define SHIFT 257
# define MOVE_SPEED 0.06
# define ROTATE_SPEED 0.035

# include "../zlibc/libft.h"
# include "struct.h"
# include "gfx.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

/* ******************* *
 * FUNCTION PROTOTYPES *
 * ******************* */

/**  game state Initialize */
int		init_soul_catcher(t_soul_catcher *game);
void	free_soul_catcher(t_soul_catcher *game);
void	free_textures(t_textures *textures);

// parse.c
int		extractfile(t_soul_catcher *game, char *line, int fd);

// parse_utils.c
int		file_signature_check(int case_n, const char *t_file);
int		is_set(t_soul_catcher *game, char **attribute_arr);
int		check_invalid_char(char *map_line);
int		update_map(t_soul_catcher *game, char *line);

// utils.c functions
int		valid_txture_color_name(char **t_ids, char *txture_color);
int		are_all_txtures_colors_set(t_textures *textures);
int		__check_color(t_soul_catcher *game, char **c_hex, char **color_value, \
		int i);
int		count_commas(char *str);

// valid_map.c
int		is_map_valid(t_soul_catcher *game);

// map_closed.c
int		is_closed(t_soul_catcher *game, char **visited, int x, int y);
int		is_closed_zero(t_soul_catcher *game, char **visited, int x, int y);

// map_utils.c
int		update_player(t_soul_catcher *game, int x, int y);
int		help_check_zero_surrounding(char **map, int y, int x);

#endif
