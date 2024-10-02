/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 06:05:30 by myousaf           #+#    #+#             */
/*   Updated: 2024/04/09 06:07:12 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii.h"

static	int	minlong(long n, int sign, char c)
{
	if ((((n == 922337203685477580) && (c > '8')) && (sign == -1))
		|| ((n > 922337203685477580) && (sign == -1)))
		return (1);
	else
		return (0);
}

static	int	maxlong(long n, int sign, char c)
{
	if (((n > 922337203685477580) && (sign == 1))
		|| ((n == 922337203685477580) && (sign == 1) && (c > '7')))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if ((str[i] == 45) || (str[i] == 43))
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (maxlong(result, sign, str[i]) == 1)
			return (-1);
		else if (minlong(result, sign, str[i]) == 1)
			return (0);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	ft_atoi_rgb(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if ((str[i] == 45) || (str[i] == 43))
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (maxlong(result, sign, str[i]) == 1)
			return (-1);
		else if (minlong(result, sign, str[i]) == 1)
			return (0);
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (result * sign);
}
