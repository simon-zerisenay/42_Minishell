/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:19:37 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 15:00:58 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_printf2(va_list ptr, char c)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_putchar('%');
	else if (c == 's')
		count += ft_putstr(va_arg(ptr, char *));
	else if (c == 'i' || c == 'd')
		count += ft_putnbr(va_arg(ptr, int));
	else if (c == 'u')
		count += ft_putuint(va_arg(ptr, unsigned int));
	else if (c == 'c')
		count += ft_putchar(va_arg(ptr, int));
	else if (c == 'x')
		count += ft_puthex_low(va_arg(ptr, unsigned int));
	else if (c == 'X')
		count += ft_puthex_up(va_arg(ptr, unsigned int));
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putpointer(va_arg(ptr, unsigned long));
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	ptr;
	int		count;

	i = 0;
	count = 0;
	va_start(ptr, s);
	while (s[i])
	{
		if (s[i] && s[i] == '%')
		{
			count += ft_printf2(ptr, s[++i]);
			i++;
		}
		while (s[i] && s[i] != '%')
		{
			ft_putchar_fd(s[i], 1);
			count++;
			i++;
		}
	}
	va_end(ptr);
	return (count);
}

/* #include <limits.h>
int	main(void)
{
	int		i;

	i = 15;
	printf("|%i\n", printf("%s", NULL));
	printf("|%i\n", ft_printf("%s", NULL));
	return (0);
}
 */
