/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 06:11:17 by myousaf           #+#    #+#             */
/*   Updated: 2024/09/26 12:23:50 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"

int		ft_printf(int fd, const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_unsignednbr(unsigned int n, int fd);
int		ft_lilx(unsigned int num);
int		ft_bigx(unsigned int num);
int		ft_ptrx(unsigned long num);

/* ***************** personal additions ************************************* */
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		perr(const char *format, ...);
// int		perr(int fd, const char *format, ...);
// int		perr(int fd, const char *format, ...);

/* ***************** graphics functions ************************************* */
void	ft_border(size_t i);

#endif