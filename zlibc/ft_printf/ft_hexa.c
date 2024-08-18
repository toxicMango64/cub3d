/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:57:49 by myousaf           #+#    #+#             */
/*   Updated: 2024/04/09 06:12:23 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include "ft_printf.h"

int	ft_lilx(unsigned int num)
{
	int		len;
	char	*s;

	len = 0;
	s = "0123456789abcdef";
	if (num > 15)
		len += ft_lilx(num / 16);
	len += ft_putchar(s[num % 16]);
	return (len);
}

int	ft_bigx(unsigned int num)
{
	int		len;
	char	*s;

	len = 0;
	s = "0123456789ABCDEF";
	if (num > 15)
		len += ft_bigx(num / 16);
	len += ft_putchar(s[num % 16]);
	return (len);
}
