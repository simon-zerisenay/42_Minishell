/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:53:36 by melsahha          #+#    #+#             */
/*   Updated: 2023/07/14 19:25:13 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		size;

	if (!src)
		return (0);
	str = (char *) ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (!str)
		return (0);
	size = 0;
	while (src[size])
	{
		str[size] = src[size];
		size++;
	}
	str[size] = '\0';
	return (str);
}
