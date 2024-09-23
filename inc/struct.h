/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:26:48 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/23 05:25:53 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../zlibc/libft.h"

/** STRUCTURES **/
typedef struct s_point
{
	double		x;
	double		y;
	char		direction;
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

typedef struct s_game
{
	int			*p_mlx;
	int			*p_win;
	t_map		*map;
	t_textures	*textures;
	t_point		*player_pos;
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
