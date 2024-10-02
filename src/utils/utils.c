/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:01:44 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 17:49:56 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	are_all_txtures_colors_set(t_textures *textures)
{
	if (textures->ceiling && textures->floor && textures->north
		&& textures->south && textures->west && textures->east)
		return (1);
	return (0);
}

int	__check_color(t_soul_catcher *game, char **c_hex, char **color_value, int i)
{
	int	c;

	c = ft_atoi_rgb(c_hex[i]);
	if (0 > c || 255 < c)
		return (EXIT_FAILURE);
	if (ft_strncmp(color_value[0], "F", 1) == 0)
		game->map->floor_color[i] = c;
	else if (ft_strncmp(color_value[0], "C", 1) == 0)
		game->map->ceiling_color[i] = c;
	return (EXIT_SUCCESS);
}

// count commas in string
int	count_commas(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}


// check if the texture/color name is valid
int	valid_txture_color_name(char **t_ids, char *txture_color)
{
	int	i;

	i = -1;
	while (t_ids[++i])
	{
		if (!ft_strcmp(t_ids[i], txture_color))
			return (1);
	}
	return (0);
}
