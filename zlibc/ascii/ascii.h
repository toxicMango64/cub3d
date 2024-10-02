/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 06:05:48 by myousaf           #+#    #+#             */
/*   Updated: 2024/04/09 12:36:18 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASCII_H
# define ASCII_H

# include "../libft.h"

int			ft_atoi(const char *str);
char		*ft_itoa(int n);
long long	ft_atoll(const char *str);
int         ft_atoi_rgb(const char *str);

#endif