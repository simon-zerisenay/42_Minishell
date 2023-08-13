/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:12:29 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 11:43:46 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	isin(char s, const char *c)
{
	int		i;
	int		size;

	size = ft_strlen(c);
	i = 0;
	while (i < size)
	{
		if (s == c[i])
			return (1);
		i ++;
	}
	return (0);
}

size_t	count_trims(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	*p;

	if (!ft_strlen(set) || !ft_strlen(s1))
		return (0);
	i = 0;
	j = ft_strlen(s1) - 1;
	p = (char *) s1;
	while (i <= j && isin(p[i], set))
		i++;
	count = i;
	while (i <= j && isin(p[j], set))
	{
		count++;
		j--;
	}
	return (count);
}

int	get_stop(char *p, char *set)
{
	int	i;

	i = ft_strlen(p) - 1;
	while (i >= 0 && isin(p[i], set))
		i--;
	return (i);
}

void	init_ret(char *ret, char *p, char *set, int stop)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stop && isin(p[i], set))
		i++;
	while (i <= stop)
	{
		ret[j] = p[i];
		i++;
		j++;
	}
	ret[j] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	char	*ret;
	int		stop;
	size_t	size;

	p = (char *) s1;
	size = ft_strlen(p) - count_trims(p, set);
	ret = (char *)malloc(size + 1);
	if (!ret || !p)
		return (0);
	stop = get_stop(p, (char *)set);
	init_ret(ret, p, (char *)set, stop);
	return (ret);
}

/* int	main(void)
{
	printf("%s\n", ft_strtrim("", "acb"));
	printf("%s\n", ft_strtrim("abc", ""));
	printf("%s\n", ft_strtrim("", ""));
	return (0);
}
 */
