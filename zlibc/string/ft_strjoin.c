/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:12:12 by myousaf           #+#    #+#             */
/*   Updated: 2024/05/06 10:52:22 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*constr;

	i = 0;
	j = 0;
	if ((!s1) && (!s2))
		return (NULL);
	constr = (char *)malloc((ft_strlen(s1)+ft_strlen(s2)) * sizeof(char) + 2);
	if (!(constr))
		return (NULL);
	while (s1[i] != '\0')
	{
		constr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		constr[i + j] = s2[j];
		j++;
	}
	constr[i + j] = '\0';
	return (constr);
}
