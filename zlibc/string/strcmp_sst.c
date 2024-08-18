/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp_sst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:50:34 by myousaf           #+#    #+#             */
/*   Updated: 2024/08/17 20:50:35 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

/**
 * @brief 
 * @param s1 ptr to string
 * @param s2 ptr to string
 * @param n 
 * @return an integer greater than, equal to, or less than 0.
 */
ssize_t	strcmp_sst(const char *s1, const char *s2, ssize_t n)
{
	if (s1 == NULL)
		return (-1);
	s1 += n;
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	if (*s1 == '\0')
		return (-1);
	if (*s2 == '\0')
		return (1);
	return (*s1 - *s2);
}
