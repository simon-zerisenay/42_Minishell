/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:12:45 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 11:14:31 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	pow_ten(int index)
{
	if (index == 0)
		return (1);
	if (index == 1)
		return (10);
	return (10 * pow_ten(index - 1));
}

static int	count_digits(long int n)
{
	int	num_digits;

	num_digits = 0;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		num_digits++;
		n = n / 10;
	}
	return (num_digits);
}

static void	print_str(long int n, int num_digits, int fd)
{
	char	c;

	while (num_digits > 0)
	{
		c = 48 + (n / (pow_ten(num_digits - 1)));
		n = n % pow_ten(num_digits - 1);
		num_digits--;
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int			num_digits;
	long int	num;

	num_digits = count_digits((long int) n);
	if (n == 0)
		num_digits = 1;
	num = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		num = num * -1;
	}
	print_str(num, num_digits, fd);
}

/* int	main(void)
{
	ft_putnbr_fd(100, 2);
	return (0);
} */
