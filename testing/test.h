#ifndef TEST_H
# define TEST_H

// // strspn

// #include "../zlibc/libft.h"
// #include "../utils/utils.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WHITESPACE	" \v\t\f\r\n"

# ifndef BONUS
#  define BONUS 0
# endif

# if BONUS

int	usage_msg(char **av)
{
	printf("BONUS!!\n");
	return (printf("Usage: %s <map_file>\n", av[0]), 1);
}
# else

int	usage_msg(char **av)
{
	return (printf("Usage: %s <map_file>\n", av[0]), 1);
}
# endif

// /** STRUCTURES **/
// typedef struct s_game			t_soul_catcher;
// typedef struct s_map			t_map;
// typedef struct s_mlx			t_mlx;
// typedef struct s_player			t_player;

// struct	s_player
// {
// 	int		x;
// 	int		y;
// 	char	direction;
// };

// struct	s_map
// {
// 	int			fd;
// 	int			width;
// 	int			floor_color[3];
// 	int			ceiling_color[3];
// 	char		**grid;
// 	char		*texture[7];
// 	t_player	*player_pos;
// };

// /**
//  * mx mouse x cordinates
//  * my mouse y cordinates
//  */
// struct	s_mlx
// {
// 	int	win_w;
// 	int	win_h;
// 	int	mx;
// 	int	my;
// 	int	forward;
// 	int	backward;
// 	int	left;
// 	int	right;
// };

// struct	s_game
// {
// 	t_mlx	*mlx;
// 	t_map	*map;
// };

#endif
