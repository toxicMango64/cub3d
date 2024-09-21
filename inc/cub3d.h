/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:51:08 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/21 21:24:50 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define TRUE 1
# define FALSE 0

# define WHITESPACE	" \v\t\f\r\n"
// # define DW		125
// # define UP		126
// # define Q		12

# ifdef OSX
#  include <mlx.h>
#  include <limits.h>
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define LEFT 123
#  define RIGHT 124
#  define SHIFT 257
# endif

# ifdef __linux__
#  include <linux/limits.h>
#  define KEY_ESC 65307
#  include "../minilibx/linux/mlx.h"
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define LEFT 65361
#  define L 123
#  define R 124
# endif

# include "../zlibc/libft.h"
# include "../utils/utils.h"
// # include "debug.h"
# include "struct.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

/* ******************* *
 * FUNCTION PROTOTYPES *
 * ******************* */

// Setup
void	init_soul_catcher(t_soul_catcher *game, t_point *player, t_map *map, \
	t_textures *textures);
int		validate(const int ac, const char * const *av);
int		map_signature_check(const char *path_to_map);

// Handlers
int		handle_destroy(t_soul_catcher *game);
int		handle_keypress(int keysym, t_soul_catcher *game);

// Parsing
int		update_map(t_soul_catcher *game, char *processed_line, char *line);
int		assign_texture(t_texture_type type, char *texture, t_soul_catcher *game);
int		is_map_valid(t_soul_catcher *game);
int		extractfile(t_soul_catcher *game, int fd);
int		is_surrounded_by_walls(t_soul_catcher *game, t_point *player_pos);

char	**intit_texture(void);
int		set_game_data(t_soul_catcher *game, char *line, char **t_ids);
int		wrerr(const char *str);
int		wr(const char *str);
char	**ft_tabdup(char **tab, char fill_char);

// Cleanup
void	free_textures(t_textures *textures);

#endif
