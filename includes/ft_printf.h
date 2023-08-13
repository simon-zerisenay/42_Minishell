/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:53:12 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 11:16:16 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putuint(unsigned int i);
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_puthex_low(unsigned int nbr);
int		ft_puthex_up(unsigned int nbr);
int		ft_putpointer(unsigned long nbr);

#endif
