/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:57:08 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 11:14:31 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i ++;
	}
	if (s1[i] && !s2[i] && i < n)
		return ((unsigned char)s1[i]);
	if (s2[i] && !s1[i] && i < n)
		return (0 - (unsigned char)s2[i]);
	return (0);
}

/* #include <stdio.h>
#include <string.h>
int main()
{
	char *a = "\200";
	char *b = "\20";
	printf("%d\n",ft_strncmp(a, b, 5));
	printf("%d\n",strncmp(a, b, 5));
	return 0;
} */
