/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:46:32 by melsahha          #+#    #+#             */
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

static void	init_str(int i, char *res, long int n, int num_digits)
{
	while (num_digits > 0)
	{
		res[i] = 48 + (n / (pow_ten(num_digits - 1)));
		n = n % pow_ten(num_digits - 1);
		num_digits--;
		i++;
	}
}

char	*ft_itoa(int n)
{
	int			num_digits;
	long int	num;
	char		*res;
	int			i;

	num_digits = count_digits((long int) n);
	if (n == 0)
		num_digits = 1;
	i = 0;
	num = n;
	if (n < 0)
	{
		i++;
		num = num * -1;
	}
	res = (char *)malloc(num_digits + i + 1);
	if (!res)
		return (0);
	if (n < 0)
		res[0] = '-';
	init_str(i, res, num, num_digits);
	res[num_digits + i] = '\0';
	return (res);
}

/* #include <stdio.h>
int	main(void)
{
	int	n;

	n = 98798;
	printf("%s\n", ft_itoa(n));
	return (0);
} */
