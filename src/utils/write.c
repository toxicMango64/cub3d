/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:58:58 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/22 13:31:13 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/debug.h"

int	wrerr(const char *str)
{
	while (str)
		write(2, str++, 1);
	return (EXIT_FAILURE);
}

int	wr(const char *str)
{
	while (str)
		write(2, str++, 1);
	return (EXIT_SUCCESS);
}
