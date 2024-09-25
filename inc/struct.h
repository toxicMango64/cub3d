/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:26:48 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/26 02:32:23 by myousaf          ###   ########.fr       */
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
	char	*full;
	char	**grid;
}	t_map;

typedef struct s_ray
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			step_size;
	double			const_rad;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				x_tex;
	double			y_tex;
	double			y_tex_step;
	int				forward;
	int				backwards;
	int				left;
	int				right;
	int				rot_left;
	int				rot_right;
}	t_ray;

typedef struct s_game
{
	int			*p_mlx;
	int			*p_win;
	t_map		*map;
	t_textures	*textures;
	t_point		*player_pos;
	t_ray		*ray;
}	t_soul_catcher;

typedef enum e_texture_types
{
	NORTH,
	EAST,
	WEST,
	SOUTH,
	FLOOR,
	CEILING
}	t_texture_type;

#endif
