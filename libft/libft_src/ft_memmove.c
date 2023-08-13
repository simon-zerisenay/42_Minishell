/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:58:42 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 11:14:31 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_memmove2(char *s, char *d, size_t len)
{
	while (len > 0)
	{
		d[len - 1] = s[len - 1];
		len--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (!d && !s)
		return (0);
	if (s > d)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		ft_memmove2(s, d, len);
	return (dst);
}

/* #include <stdio.h>
int	main(void)
{
	int size = 15;
	char dest[size];
	char src[] = "source";
	printf("%s\n", ft_memmove(dest, src, size));
	return (0);
}
 */
