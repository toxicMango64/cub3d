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

#include "ft_printf.h"

static	int	ft_xforptr(unsigned long num)
{
	int		len;
	char	*s;

	len = 0;
	s = "0123456789abcdef";
	if (num > 15)
		len += ft_xforptr(num / 16);
	len += ft_putchar(s[num % 16]);
	return (len);
}

int	ft_ptrx(unsigned long num)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	if (num == 0)
		len += ft_putchar('0');
	else
		len += ft_xforptr(num);
	return (len);
}
