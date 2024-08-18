/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:58:01 by myousaf           #+#    #+#             */
/*   Updated: 2024/05/06 10:51:35 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static void	free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static	int	wordcounter(char const *s, char c)
{
	int	i;
	int	subnum;

	i = 0;
	subnum = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		if ((s[i] != '\0') && (s[i] != c))
		{
			subnum++;
		}
		while ((s[i] != '\0') && (s[i] != c))
		{
			i++;
		}
	}
	return (subnum);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**substrs;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	substrs = (char **)malloc (sizeof(char *) * (wordcounter(s, c) + 1));
	if (!(substrs) || !(s))
		return (NULL);
	while (j < wordcounter(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		while ((s[i] != '\0') && (s[i] != c))
			i++;
		substrs[j] = ft_substr(s, start, i - start);
		if (!substrs[j])
			return (free_all(substrs), NULL);
		j++;
	}
	return (substrs[j] = NULL, substrs);
}
