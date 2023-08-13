/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:21:28 by melsahha          #+#    #+#             */
/*   Updated: 2023/07/21 15:25:49 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (!ft_strncmp(s1, s2, ft_strlen(s2))
		&& !ft_strncmp(s1, s2, ft_strlen(s1)))
		return (0);
	return (1);
}
