/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:21:56 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 11:14:31 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	start;
	size_t	i;
	int		ret;

	if (!dstsize && !dst)
		return (0);
	start = ft_strlen(dst);
	if (start >= dstsize)
		return (dstsize + ft_strlen(src));
	else
		ret = start + ft_strlen(src);
	i = 0;
	while (src[i] && (start + i) < dstsize - 1)
	{
		dst[start + i] = src[i];
		i ++;
	}
	dst[start + i] = '\0';
	return (ret);
}
