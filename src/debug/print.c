/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:28:43 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/21 21:28:58 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "debug.h"

void	print_info(t_textures textures, t_map map)
{
	puts("Texture Paths: ");
	if (printf("North texture: ") && puts(textures.north) && !textures.north)
		printf("North texture: ERROR!");
	if (printf("East texture: ") && puts(textures.east) && !textures.east)
		printf("East texture: ERROR!");
	if (printf("West texture: ") && puts(textures.west) && !textures.west)
		printf("West texture: ERROR!");
	if (printf("South texture: ") && puts(textures.south) && !textures.south)
		printf("South texture: ERROR!");
	if (printf("F color: ") && puts(textures.floor) && !textures.floor)
		printf("Floor texture: ERROR!");
	if (printf("C color: ") && puts(textures.ceiling) && !textures.ceiling)
		printf("Ceiling texture: ERROR!");
	if (map.full)
		(puts("\nMap: "), puts(map.full));
}
