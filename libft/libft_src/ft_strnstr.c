/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:25:38 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 11:44:01 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nsize;
	size_t	hsize;
	char	*h;

	h = (char *) haystack;
	if (!len && !h)
		return (0);
	i = 0;
	nsize = ft_strlen((char *)needle);
	hsize = ft_strlen(haystack);
	if (!hsize && !nsize)
		return ("");
	if (!hsize)
		return (0);
	while (i + nsize <= len)
	{
		if (h[0] && ft_strncmp(h, (char *)needle, nsize) == 0)
			return (h);
		i++;
		h++;
	}
	return (0);
}

/* #include <string.h>
int main()
{
	char *h = "";
	char *n = "asdf";
	size_t	len = 4563;
	printf("%s\n",ft_strnstr(h, n, len));
	printf("%s\n",strnstr(h, n, len));
	return 0;
} */

/*
h 0, n 0, l 0 -> empty | null
h 0, n 0, l x ->empty | ??
h 0, n x, l x -> null | null

h 0, n 0, l x -> empty | empty
h x, n 0, l 0 -> null | null


*/
