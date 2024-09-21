/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 06:38:37 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/21 21:30:22 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_textures *textures)
{
	if (textures->north || printf("error: could not free north texture\n"))
		free(textures->north);
	if (textures->east || printf("error: could not free east texture\n"))
		free(textures->east);
	if (textures->west || printf("error: could not free west texture\n"))
		free(textures->west);
	if (textures->south || printf("error: could not free south texture\n"))
		free(textures->south);
	if (textures->floor)
		free(textures->floor);
	if (textures->ceiling)
		free(textures->ceiling);
}

// void	free_textures(t_textures *textures)
// {
// 	if (!textures)
// 	{
// 		printf("textures: {NULL}\n");
// 		return ;
// 	}
// 	if (textures->north)
// 		(printf("texture: {%s}\n", textures->north), free(textures->north));
// 	else
// 		printf("texture: {north}\n");
// 	if (textures->east)
// 		(printf("texture: {%s}\n", textures->east), free(textures->east));
// 	else
// 		printf("texture: {east}\n");
// 	if (textures->west)
// 		(printf("texture: {%s}\n", textures->west), free(textures->west));
// 	else
// 		printf("texture: {west}\n");
// 	if (textures->south)
// 		(printf("texture: {%s}\n", textures->south), free(textures->south));
// 	else
// 		printf("texture: {south}\n");
// 	if (textures->floor)
// 		(printf("texture: {%s}\n", textures->floor), free(textures->floor));
// 	else
// 		printf("texture: {floor}\n");
// 	if (textures->ceiling)
// 		(printf("texture: {%s}\n", textures->ceiling), free(textures->ceiling));
// 	else
// 		printf("texture: {ceiling}\n");
// }
