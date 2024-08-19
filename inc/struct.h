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

/** STRUCTURES **/
typedef struct s_game			t_soul_catcher;
typedef struct s_texture		t_texture;
typedef struct s_map			t_map;
typedef struct s_mlx			t_mlx;
typedef struct s_point			t_point;
typedef struct s_colorscheme	t_colorscheme;

struct	s_point
{
	int	x;
	int	y;
};

struct	s_texture
{
	char	*path;
	int		width;
	int		height;
};

struct	s_map
{
	char		**grid;
	int			width;
	int			height;
	int			floor_color[3];
	int			ceiling_color[3];
	t_point		*player_pos;
	t_texture	*north_texture;
	t_texture	*south_texture;
	t_texture	*east_texture;
	t_texture	*west_texture;
};

/**
 * mx mouse x cordinates
 * my mouse y cordinates
 */
struct	s_mlx
{
	int				win_w;
	int				win_h;
	int				mx;
	int				my;
	int				forward;
	int				backward;
	int				left;
	int				right;
};

/**
 * char f Floor color
 * char c Ceiling color
 * char no North wall color
 * char ea East wall color
 * char we West wall color
 * char so South wall color
 */
struct s_colorscheme
{
	// int		f[3];
	// int		c[3];
	char	*f;
	char	*c;
	char	*no;
	char	*ea;
	char	*we;
	char	*so;
};

struct	s_game
{
	t_mlx			*mlx;
	t_map			*map;
	t_colorscheme	*scheme;
};

#endif
