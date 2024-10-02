#include "debug.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:26:48 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/26 14:15:46 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../zlibc/libft.h"

/** STRUCTURES **/
typedef struct s_point
{
	int		spawn_x;
	int		spawn_y;
	char	direction;
}	t_point;

typedef struct s_textures
{
	char	*north;
	char	*east;
	char	*west;
	char	*south;
	char	*floor;
	char	*ceiling;
}	t_textures;

typedef struct s_map
{
	int		fd;
	int		floor_color[3];
	int		ceiling_color[3];
	int		width;
	int		height;
	char	*full;
	char	**grid;
}	t_map;

typedef struct s_img
{
	void		*ptr;
	char		*adr;
	char		dir;
	int			endian;
	int			bpp;
	int			len;
	int			width;
	int			height;
}	t_img;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_player
{
	char	facing;
	int		x;
	int		y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_draw
{
	int		line_h;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	double	wall_x;
	double	step;
	double	texpos;
}	t_draw;


typedef struct s_game
{
	void		*p_mlx;
	void		*p_win;
	t_map		*map;
	t_textures	*textures;
	t_point		*player_pos;

	//added
	t_ray		*ray;
	t_player	*player;
	t_img		frame;
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	int			draw_flag;

}	t_soul_catcher;

typedef enum e_texture_types
{
	NORTH,
	EAST,
	WEST,
	SOUTH,
	FLOOR,
	CEILING,
	MAP,
	TEXTURE
}	t_texture_type;

#endif
