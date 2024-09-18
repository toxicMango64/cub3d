#ifndef CUB3D_H
# define CUB3D_H

# define TRUE 1
# define FALSE 0

# define WHITESPACE	" \v\t\f\r\n"
# define L		123
# define R		124
# define DW		125
# define UP		126

# define W		13
# define A		0
# define S		1
# define D		2

# define Q		12

# ifdef __linux__
#  include <linux/limits.h>
#  define KEY_ESC 65307
# else
#  include <limits.h>
#  define KEY_ESC 53
# endif
# include "../zlibc/libft.h"
# include "../utils/utils.h"
# include "../utils/utils.h"
# include "debug.h"
# include "struct.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		validate_map(const char *path_to_map, t_soul_catcher *game);
char	**intit_texture(void);
int		set_game_data(t_soul_catcher *game, char *line, char **t_ids);

#endif
