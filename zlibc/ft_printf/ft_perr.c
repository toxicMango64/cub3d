/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:56:25 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/27 19:29:27 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_border(size_t i)
// {
// 	while (i > 0)
// 	{
// 		ft_printf("\e[31m-");
// 		i--;
// 	}
// 	write(1, "\n", 1);
// }

// does not exit with int status anymore
// void	perr(char *str, int int_status)
// {
// 	size_t	i;

// 	(void)int_status;
// 	i = ft_strlen(str) + 13;
// 	ft_border(i);
// 	ft_printf(" Error ya: ");
// 	ft_printf("%s\n", str);
// 	ft_border(i);
// }

static	int	ft_format(int fd, char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fd(va_arg(args, int), fd);
	else if (c == 's')
		len += ft_putstr_fd(va_arg(args, char *), fd);
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_fd(va_arg(args, int), fd);
	else if (c == 'u')
		len += ft_unsignednbr(va_arg(args, unsigned int), fd);
	else if (c == 'x')
		len += ft_lilx(va_arg(args, unsigned int));
	else if (c == 'X')
		len += ft_bigx(va_arg(args, unsigned int));
	else if (c == 'p')
		len += ft_ptrx(va_arg(args, unsigned long));
	else if (c == '%')
		len += ft_putchar_fd('%', fd);
	else
		len += ft_putchar_fd(c, fd);
	return (len);
}

int	perr(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	ft_putstr_fd("Error\n", 2);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			len += ft_format(2, format[++i], args);
		}
		else
			len += ft_putchar_fd(format[i], 2);
		i++;
	}
	len += ft_putchar_fd('\n', 2);
	va_end (args);
	return (len);
}

// void	perr(char *str, int int_status)
// {
// 	size_t	i;

// 	i = ft_strlen(str) + 13;
// 	ft_border(i);
// 	ft_printf(" Error ya: ");
// 	ft_printf("%s\n", str);
// 	ft_border(i);
// 	exit (int_status);
// }

// void	mperr(char *str)
// {
// 	size_t	i;

// 	i = ft_strlen(str) + 13;
// 	ft_border(i);
// 	ft_printf(" Error ya: ");
// 	ft_printf("%s", str);
// 	ft_printf("\n\e[90mKinda reminds me of my wife. cc: ;)\e[0m");
// 	ft_border(i);
// }

// void	ft_error(char *str)
// {
// 	size_t	i;

// 	i = ft_strlen(str) + 12;
// 	ft_border(i);
// 	ft_printf("\e[90m====>\e[0m]");
// 	ft_printf("\e[31m%s", str);
// 	ft_printf("\n\e[90m<====\e[0m]");
// 	ft_border(i);
// }
