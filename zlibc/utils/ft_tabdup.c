/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:04:10 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 18:07:01 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strac(char *str, char c)
{
	char	*new_str;
	int		i;
	char	append_char[2];

	append_char[0] = c;
	append_char[1] = '\0';
	if (!str)
		return (ft_strdup(append_char));
	new_str = malloc(ft_strlen(str) + 2);
	if (!new_str)
		return (NULL);
	i = -1;
	while (str[++i])
		new_str[i] = str[i];
	new_str[i++] = c;
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

static char	check_char(char c)
{
	char	zero;

	zero = '0';
	if (ft_strchr(WHITESPACE, c))
		return (c);
	return (zero);
}

static char	**tab_help(char **new_tab, char *str)
{
	new_tab = malloc(sizeof(char *) * 2);
	if (!new_tab)
		return (NULL);
	new_tab[0] = ft_strdup(str);
	new_tab[1] = NULL;
	return (new_tab);
}

char	**ft_tabjoin(char **tab, char *str)
{
	int		width;
	int		i;
	char	**new_tab;

	new_tab = NULL;
	if (!tab)
		return (tab_help(new_tab, str));
	width = 0;
	i = -1;
	while (tab[width])
		width++;
	new_tab = malloc(sizeof(char *) * (width + 2));
	if (!new_tab)
		return (NULL);
	while (++i < width)
		new_tab[i] = ft_strdup(tab[i]);
	new_tab[i++] = ft_strdup(str);
	new_tab[i] = NULL;
	freearr(tab);
	return (new_tab);
}

char	**ft_tabdup(char **tab, char fill_char, int x, int y)
{
	char	**duped_tab;
	char	*line;

	y = -1;
	duped_tab = NULL;
	while (tab[++y])
	{
		x = -1;
		line = NULL;
		while (tab[y][++x])
		{
			if (!fill_char)
				line = ft_strac(line, tab[y][x]);
			else
				line = ft_strac(line, check_char(tab[y][x]));
			if (!line)
				return (freearr(duped_tab), NULL);
		}
		duped_tab = ft_tabjoin(duped_tab, line);
		if (!duped_tab)
			return (free(line), NULL);
		free(line);
	}
	return (duped_tab);
}
