/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:14:11 by szerisen          #+#    #+#             */
/*   Updated: 2023/05/10 18:05:25 by szerisen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

char	*joinandfree(char *resultant, char *appender)
{
	char	*temp;

	temp = ft_strjoin(resultant, appender);
	free(resultant);
	return (temp);
}

char	*find_remaining(char *resultant)
{
	int		i;
	int		j;
	char	*remstatic;

	i = 0;
	while (resultant[i] && resultant[i] != '\n')
		i++;
	if (!resultant[i])
	{
		free(resultant);
		return (NULL);
	}
	remstatic = ft_calloc((ft_strlen(resultant) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (resultant[i])
		remstatic[j++] = resultant[i++];
	free(resultant);
	return (remstatic);
}

char	*find_line(char *resultant)
{
	char	*one_line;
	int		i;

	i = 0;
	if (!resultant[i])
		return (NULL);
	while (resultant[i] && resultant[i] != '\n')
		i++;
	one_line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (resultant[i] && resultant[i] != '\n')
	{
		one_line[i] = resultant[i];
		i++;
	}
	if (resultant[i] && resultant[i] == '\n')
		one_line[i++] = '\n';
	return (one_line);
}

char	*read_file(int fd, char *resultant)
{
	char	*appender;
	int		noofbytes;

	if (!resultant)
		resultant = ft_calloc(1, 1);
	appender = ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	noofbytes = 1;
	while (noofbytes > 0)
	{
		noofbytes = read(fd, appender, BUFFER_SIZE);
		if (noofbytes == -1)
		{
			free(appender);
			return (NULL);
		}
		appender[noofbytes] = 0;
		resultant = joinandfree(resultant, appender);
		if (ft_strchr(resultant, '\n'))
			break ;
	}
	free(appender);
	return (resultant);
}

char	*get_next_line(int fd)
{
	static char	*container_static[256];
	char		*one_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (BUFFER_SIZE > 2147483647)
		return (NULL);
	container_static[fd] = read_file(fd, container_static[fd]);
	if (!container_static[fd])
		return (NULL);
	one_line = find_line(container_static[fd]);
	container_static[fd] = find_remaining(container_static[fd]);
	return (one_line);
}

// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>

// int main(){
// 	int fd1;
// 	int fd2;
// 	int fd3;
// 	fd1 = open("/Users/szerisen/Desktop/simon.txt", O_RDONLY);
// 	fd2 = open("/Users/szerisen/Desktop/secsimon.txt", O_RDONLY);
// 	fd3 = open("/Users/szerisen/Desktop/thirsimon.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd3));
// 	// char *simon[0] = {"s", "meawi"};
// }
