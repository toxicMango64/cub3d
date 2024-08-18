/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 06:11:17 by myousaf           #+#    #+#             */
/*   Updated: 2024/04/09 06:53:54 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_unsignednbr(unsigned int n);
int		ft_lilx(unsigned int num);
int		ft_bigx(unsigned int num);
int		ft_ptrx(unsigned long num);

/* ***************** personal additions ************************************* */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	perr(char *str, int int_status);

/* ***************** graphics functions ************************************* */
void	ft_border(size_t i);

#endif