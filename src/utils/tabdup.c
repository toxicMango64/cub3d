/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:04:10 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/21 21:27:08 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	i = -1;
	while (str[++i])
		new_str[i] = str[i];
	new_str[i++] = c;
	new_str[i] = '\0';
	free(str);
	str = new_str;
	return (new_str);
}

char	**ft_tabjoin(char **tab, char *str)
{
	int		width;
	int		i;
	char	**new_tab;

	new_tab = NULL;
	if (!tab)
	{
		new_tab = malloc(sizeof(char *) * 2);
		new_tab[0] = ft_strdup(str);
		new_tab[1] = NULL;
		return (new_tab);
	}
	width = 0;
	i = -1;
	while (tab[width])
		width++;
	new_tab = malloc(sizeof(char *) * (width + 2));
	while (++i < width)
		new_tab[i] = ft_strdup(tab[i]);
	new_tab[i++] = ft_strdup(str);
	new_tab[i] = NULL;
	freearr(tab);
	return (new_tab);
}

static char	check_char(char c)
{
	char	zero;

	zero = '0';
	if (ft_strchr(WHITESPACE, c))
		return (c);
	return (zero);
}

char	**ft_tabdup(char **tab, char fill_char)
{
	int		y;
	int		x;
	char	**duped_tab;
	char	*line;

	y = 0;
	duped_tab = NULL;
	line = NULL;
	while (tab[y])
	{
		x = -1;
		while (tab[y][++x])
		{
			if (!fill_char)
				line = ft_strac(line, tab[y][x]);
			else
				line = ft_strac(line, check_char(tab[y][x]));
		}
		duped_tab = ft_tabjoin(duped_tab, line);
		free(line);
		line = NULL;
		y++;
	}
	return (duped_tab);
}