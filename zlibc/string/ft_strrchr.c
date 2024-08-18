/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:10:29 by myousaf           #+#    #+#             */
/*   Updated: 2024/05/06 10:52:51 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strrchr(const char *s, int c)
{
	char	n;
	char	*str;
	int		i;
	int		len;

	n = (char)c;
	str = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	len = i;
	while (len >= 0)
	{
		if (s[len] == n)
		{
			return (str + len);
		}
		len--;
	}
	return (NULL);
}
