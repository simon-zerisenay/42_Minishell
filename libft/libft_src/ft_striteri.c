/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:34:09 by melsahha          #+#    #+#             */
/*   Updated: 2022/11/13 21:05:09 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>
void	ft_tolower(unsigned int i, char *c)
{
	if (*c >= 'A' && *c <= 'Z' && i > 2)
		*c += 32;
}

int	main(void)
{
	char	s[] = "HELLO";

	printf("%s\n", s);
	ft_striteri(s, ft_tolower);
	printf("%s\n", s);
	return(0);
}
 */
