/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:56:25 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/26 04:47:26 by myousaf          ###   ########.fr       */
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

// int	fd_putchar(int fd, int c)
// {
// 	return (write(fd, &c, 1));
// }

// int	fd_putstr(int fd, char *s)
// {
// 	int	i;
// 	int	len;

// 	if (s == NULL)
// 		s = "(null)";
// 	i = -1;
// 	len = 0;
// 	while (s[++i])
// 		len += fd_putchar(fd, s[i]);
// 	return (len);
// }

// void	ft_print_arr(char **arr)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("\e[90marr = [");
// 	while (arr[i])
// 	{
// 		if (i != 0)
// 			ft_printf(", ");
// 		ft_printf("{%s}", arr[i]);
// 		i++;
// 	}
// 	ft_printf("]\e[0m\n");
// }

// void	ft_print_intarr(int **arr)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("\e[90marr = [");
// 	while (arr[i])
// 	{
// 		if (i != 0)
// 			ft_printf(", ");
// 		ft_printf("{%s}", arr[i]);
// 		i++;
// 	}
// 	ft_printf("]\e[0m\n");
// }
