/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 06:15:57 by myousaf           #+#    #+#             */
/*   Updated: 2024/10/02 18:06:22 by myousaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define WHITESPACE	" \v\t\f\r\n"

# include "../libft.h"

int		arr_size(char **arr);
char	**ft_tabdup(char **tab, char fill_char, int x, int y);

#endif
