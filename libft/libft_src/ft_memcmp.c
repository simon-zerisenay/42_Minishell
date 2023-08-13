/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:43:36 by melsahha          #+#    #+#             */
/*   Updated: 2022/11/11 18:25:16 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*p1;
	char			*p2;

	p1 = (char *) s1;
	p2 = (char *) s2;
	i = 0;
	while (i < n)
	{
		if (*p1 != *p2)
			return ((unsigned char) *p1 - (unsigned char) *p2);
		i ++;
		p1 ++;
		p2 ++;
	}
	return (0);
}
/* #include <stdio.h>
#include <string.h>
int main()
{
	char *a = "12375";
	char *b = "12945";
	printf("%d\n",ft_memcmp(a, b, 5));
	printf("%d\n",memcmp(a, b, 5));
	return 0;
}
 */
