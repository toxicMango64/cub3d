/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:32:23 by myousaf           #+#    #+#             */
/*   Updated: 2024/04/09 06:15:33 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*sr;
	unsigned char	*des;
	size_t			i;

	i = 0;
	sr = (unsigned char *)src;
	des = (unsigned char *)dest;
	if (src == dest)
		return (dest);
	if (src < dest)
	{
		while (len--)
			des[len] = sr[len];
	}
	else
	{
		while (i < len)
		{
			des[i] = sr[i];
			i++;
		}
	}
	return (dest);
}
