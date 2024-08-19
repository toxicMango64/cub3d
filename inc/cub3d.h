#ifndef CUB3D_H
# define CUB3D_H

# define TRUE 1
# define FALSE 0

# define F	'F'
# define C	'C'
# define NO	'NO'
# define SO	'SO'
# define WE	'WE'
# define EA	'EA'
# define WHITESPACES	" \v\t\f\r\n"

# ifdef __linux__
#  include <linux/limits.h>
# else
#  include <limits.h>
# endif
# include "../zlibc/libft.h"
# include "../utils/utils.h"
# include "struct.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

void	validate_map(char *path_to_map, t_soul_catcher *game);
void	init_cub3d(t_soul_catcher *game);
// t_map	parse_map_file(char *filename);

#endif
