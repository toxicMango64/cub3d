/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:26:48 by myousaf           #+#    #+#             */
/*   Updated: 2024/08/16 16:26:49 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../zlibc/libft.h"

/** STRUCTURES **/
typedef struct s_game			t_soul_catcher;
typedef struct s_map			t_map;
typedef struct s_mlx			t_mlx;
typedef struct s_point			t_point;

struct	s_point
{
	int	x;
	int	y;
};

struct	s_map
{
	int			fd;
	int			width;
	int			height;
	int			floor_color[3];
	int			ceiling_color[3];
	char		**grid;
	char		*texture[7];
	t_point		*player_pos;
};

/**
 * mx mouse x cordinates
 * my mouse y cordinates
 */
struct	s_mlx
{
	int	*p_mlx;
	int	*p_win;
	int	mx;
	int	my;
	int	forward;
	int	backward;
	int	left;
	int	right;
};

struct	s_game
{
	t_mlx	*mlx;
	t_map	*map;
};

#endif
