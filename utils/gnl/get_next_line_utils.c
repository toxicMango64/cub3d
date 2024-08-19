/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:30:01 by myousaf           #+#    #+#             */
/*   Updated: 2024/06/05 23:01:37 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strcpy_gnl(char *src, char *dest)
{
	unsigned int	i;

	i = -1;
	while (src[++i] != '\0')
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup_gnl(char *src)
{
	unsigned int	i;
	char			*dest;

	i = ft_strlen_gnl(src);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!(dest))
		return (free(dest), NULL);
	return (ft_strcpy_gnl(src, dest));
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*constr;

	i = -1;
	j = -1;
	if (!s1 || !*s1)
		return (ft_strdup_gnl((char *)s2));
	if (!s2 || !*s2)
		return (ft_strdup_gnl((char *)s1));
	constr = (char *)malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2))
			* sizeof(char) + 1);
	if (!(constr))
		return (free (constr), NULL);
	while (s1[++i] != '\0')
		constr[i] = s1[i];
	while (s2[++j] != '\0')
		constr[i + j] = s2[j];
	constr[i + j] = '\0';
	return (constr);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char	n;
	char	*str;
	int		i;

	n = (char)c;
	str = (char *)s;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == n)
			return (str + i);
	}
	if (str[i] == n)
		return (str + i);
	return (NULL);
}
