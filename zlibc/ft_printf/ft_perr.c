/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:56:25 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/25 23:11:37 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_border(size_t i)
{
	while (i > 0)
	{
		ft_printf("\e[31m-");
		i--;
	}
	write(1, "\n", 1);
}

// does not exit with int status anymore
void	perr(char *str, int int_status)
{
	size_t	i;

	(void)int_status;
	i = ft_strlen(str) + 13;
	ft_border(i);
	ft_printf(" Error ya: ");
	ft_printf("%s\n", str);
	ft_border(i);
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

void	mperr(char *str)
{
	size_t	i;

	i = ft_strlen(str) + 13;
	ft_border(i);
	ft_printf(" Error ya: ");
	ft_printf("%s", str);
	ft_printf("\n\e[90mKinda reminds me of my wife. cc: ;)\e[0m");
	ft_border(i);
}

void	ft_error(char *str)
{
	size_t	i;

	i = ft_strlen(str) + 12;
	ft_border(i);
	ft_printf("\e[90m====>\e[0m]");
	ft_printf("\e[31m%s", str);
	ft_printf("\n\e[90m<====\e[0m]");
	ft_border(i);
}
