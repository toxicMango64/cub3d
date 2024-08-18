/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:12:11 by myousaf           #+#    #+#             */
/*   Updated: 2024/04/09 06:15:24 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	if ((!count) || (!size))
	{
		memory = malloc(1);
		if (!(memory))
			return (NULL);
		return (memory);
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	memory = malloc(size * count);
	if (!(memory))
		return (NULL);
	else
		ft_bzero(memory, size * count);
	return (memory);
}
