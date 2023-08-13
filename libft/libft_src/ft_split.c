/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:39:31 by melsahha          #+#    #+#             */
/*   Updated: 2023/07/21 15:38:26 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_words(char *s, char c)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			res++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (res);
}

static void	init_word(char *d, char *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start + i] && s[start + i] != c)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
}

static void	init_arr(char **arr, char *s, char c)
{
	int	i;
	int	j;
	int	word_size;

	i = 0;
	j = 0;
	while (s[i])
	{
		word_size = 0;
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				i++;
				word_size++;
			}
			arr[j] = (char *) malloc(word_size + 1);
			init_word(arr[j], s, c, i - word_size);
			j++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		num_words;
	char	**arr;

	num_words = count_words((char *) s, c);
	arr = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!arr)
		return (0);
	init_arr(arr, (char *) s, c);
	arr[num_words] = 0;
	return (arr);
}

/* int	main(int c, char **v)
{
	int		i;
	char	**arr;

	i = c - c;
	arr = ft_split(v[1], ' ');
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	return (0);
}
 */
