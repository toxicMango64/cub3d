/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:10:29 by myousaf           #+#    #+#             */
/*   Updated: 2024/05/06 10:52:47 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)haystack;
	i = 0;
	j = 0;
	while ((str[i + j] != '\0') && (needle[j] != '\0') && (i < len)
		&& (i + j < len))
	{
		if (str[i + j] == needle[j])
		{
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
	if (needle[j] == '\0')
		return (str + i);
	else
		return (0);
}
