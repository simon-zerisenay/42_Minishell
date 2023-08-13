/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:55:55 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 11:14:31 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*p;
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	p = (char *) s;
	if (start >= size)
		ret = (char *) malloc(1);
	else if (len >= size)
		ret = (char *) malloc(size + 1);
	else
		ret = (char *) malloc(len + 1);
	if (!ret || !p)
		return (0);
	i = 0;
	while (i < len && start + i < size)
	{
		ret[i] = p[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

/* #include <stdio.h>
int	main(void)
{
	char * s = "the longer string";
	unsigned int start = 1000;
	size_t len = 42000;
	printf("ret |%s|\n", ft_substr(s, start, len));
	return 0;
} */
