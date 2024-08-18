/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:10:29 by myousaf           #+#    #+#             */
/*   Updated: 2024/04/09 06:07:05 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii.h"

static int	nblen(long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*result;
	long int	nb;

	nb = (long int )n;
	len = nblen(nb);
	result = (char *)malloc(len * sizeof(char) + 1);
	if (!(result))
		return (NULL);
	result[len] = '\0';
	len--;
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		result[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (result);
}
