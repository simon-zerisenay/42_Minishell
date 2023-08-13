/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:33:44 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 11:14:31 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	int		i;
	int		j;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	ret = malloc(count * size);
	if (!ret)
		return (0);
	i = 0;
	j = count * size;
	while (i < j)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}

/* #include <string.h>
int	main(void)
{
	int size = 8539;

	void * d1 = ft_calloc(size, sizeof(int));
	void * d2 = calloc(size, sizeof(int));

	printf("\n%i\n",memcmp(d1, d2, size * sizeof(int)));
	printf("right?\n");
	free(d1);
	free(d2);
	return 0;
} */
