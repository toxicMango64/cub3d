/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:56:25 by myousaf           #+#    #+#             */
/*   Updated: 2024/04/09 12:41:47 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i])
	{
		len += ft_putchar(s[i]);
		i++;
	}
	return (len);
}

// int	fd_putchar(int c, int fd)
// {
// 	return (write(fd, &c, 1));
// }

// int	fd_putstr(char *s, int fd)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = 0;
// 	if (s == NULL)
// 		s = "(null)";
// 	while (s[i])
// 	{
// 		len += fd_putchar(s[i], fd);
// 		i++;
// 	}
// 	return (len);
// }

void	ft_print_arr(char **arr)
{
	int	i;

	i = 0;
	ft_printf("\e[90marr = [");
	while (arr[i])
	{
		if (i != 0)
			ft_printf(", ");
		ft_printf("{%s}", arr[i]);
		i++;
	}
	ft_printf("]\e[0m\n");
}

void	ft_print_intarr(int **arr)
{
	int	i;

	i = 0;
	ft_printf("\e[90marr = [");
	while (arr[i])
	{
		if (i != 0)
			ft_printf(", ");
		ft_printf("{%s}", arr[i]);
		i++;
	}
	ft_printf("]\e[0m\n");
}
