/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:38:58 by nosman            #+#    #+#             */
/*   Updated: 2024/05/16 06:53:12 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen_perr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_border(size_t i)
{
	while (i > 0)
	{
		ft_printf("\e[31m-");
		i--;
	}
	write(1, "\n", 1);
}

void	perr(char *str, int int_status)
{
	size_t	i;

	i = ft_strlen_perr(str) + 13;
	ft_border(i);
	ft_printf(" Error ya: ");
	ft_printf("%s\n", str);
	ft_border(i);
	exit (int_status);
}

void	mperr(char *str)
{
	size_t	i;

	i = ft_strlen_perr(str) + 13;
	ft_border(i);
	ft_printf(" Error ya: ");
	ft_printf("%s", str);
	ft_printf("\n\e[90mKinda reminds me of my wife. cc: ;)\e[90m");
	ft_border(i);
	exit (1);
}

void	ft_error(char *str)
{
	size_t	i;

	i = ft_strlen_perr(str) + 12;
	ft_border(i);
	ft_printf("\e[90m====>\e[0m]");
	ft_printf("\e[31m%s", str);
	ft_printf("\n\e[90m<====\e[0m]");
	ft_border(i);
	exit (1);
}
