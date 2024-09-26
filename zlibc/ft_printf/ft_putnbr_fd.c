/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:10:29 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/26 04:58:14 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int nb, int fd)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	else if (nb < 0)
	{
		len += ft_putchar_fd('-', fd);
		nb = nb * -1;
		len += ft_putnbr_fd(nb, fd);
	}
	else if (nb >= 10)
	{
		len += ft_putnbr_fd(nb / 10, fd);
		len += ft_putchar_fd(nb % 10 + '0', fd);
	}
	else
		len += ft_putchar_fd(nb + '0', fd);
	return (len);
}
