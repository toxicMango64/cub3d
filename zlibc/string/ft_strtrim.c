/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:14:30 by myousaf           #+#    #+#             */
/*   Updated: 2024/05/06 10:52:56 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static	size_t	start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0') && (ft_strchr(set, s1[i])))
		i++;
	return (i);
}

static	size_t	end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	slen;

	i = 0;
	j = 0;
	slen = ft_strlen(s1) - 1;
	while ((s1[i] != '\0') && (ft_strchr(set, s1[slen])))
	{
		slen--;
		j++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		ends;
	size_t		starts;
	size_t		r;
	char		*trimmed;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	starts = start(s1, set);
	ends = end(s1, set);
	r = ft_strlen(s1) - starts - ends;
	if (starts + ends >= ft_strlen(s1))
		return (ft_strdup(""));
	trimmed = (char *)malloc((r + 1) * sizeof(char));
	if (!(trimmed))
		return (NULL);
	while (i < r)
	{
		trimmed[i] = s1[starts];
		starts++;
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
