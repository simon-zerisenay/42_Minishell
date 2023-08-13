/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:01:57 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 15:01:11 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	pow_ten(int index)
{
	if (index == 0)
		return (1);
	if (index == 1)
		return (10);
	return (10 * pow_ten(index - 1));
}

static int	count_digits(unsigned int n)
{
	int	num_digits;

	num_digits = 0;
	while (n > 0)
	{
		num_digits++;
		n = n / 10;
	}
	return (num_digits);
}

static void	print_str(unsigned int n, int num_digits)
{
	char	c;

	while (num_digits > 0)
	{
		c = 48 + (n / (pow_ten(num_digits - 1)));
		n = n % pow_ten(num_digits - 1);
		num_digits--;
		write(1, &c, 1);
	}
}

int	ft_putuint(unsigned int n)
{
	int				num_digits;
	unsigned int	num;

	num_digits = count_digits((long int) n);
	if (n == 0)
		num_digits = 1;
	num = n;
	print_str(num, num_digits);
	return (num_digits);
}
