/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:02:15 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/23 18:25:42 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*bufcpy(int j, char *buffer, char *s)
{
	s = (char *) realloc(s, (j + 1));
	if (s == NULL)
		return (NULL);
	strcat(s, buffer);
	return (s);
}

// char *bufferset(char c, int i, char *buffer)

char	*ft_get_next_line(int fd)
{
	size_t			i;
	static int		j;
	static char		*buffer;
	char			c;
	char			*s;

	buffer = (char *) calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	s = (char *) calloc(sizeof(char), 1);
	if (s == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (read(fd, &c, 1) != 0)
	{
		if (c != '\n' && ++i < (BUFFER_SIZE))
			buffer[i] = c;
		else if (c != '\n' && i == (BUFFER_SIZE))
		{
			buffer[i] = c;
			buffer[i + 1] = 0;
			j = j + i;
			s = bufcpy(j, buffer, s);
			i = -1;
		}
		else if (c == '\n')
		{
			i++;
			j = j + i + 1;
			buffer[i] = c;
			buffer[i + 1] = 0;
			s = bufcpy(j, buffer, s);
			free(buffer);
			return (s);
		}
	}
	if (j != 0)
	{
		j = j + BUFFER_SIZE;
		buffer[i] = c;
		buffer[i + 1] = 0;
		s = bufcpy(j, buffer, s);
		free(buffer);
		return (s);
	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*c;
	char	*s;
	int		i;

	fd = open("/Users/aalshafy/Desktop/cursusdraft/ft_getnextline/new.txt", O_RDWR | O_CREAT, 0640);
	if (fd < 0)
		return 2;
	i = 0;
	s = ft_get_next_line(fd);
	while (s)
	{
		printf("%s\n", s);
		s = ft_get_next_line(fd);
		i++;
	}
	// c = ft_get_next_line(fd);
	// printf("%s\n", c);
	// c = ft_get_next_line(fd);
	// printf("%s\n", c);
	// c = ft_get_next_line(fd);
	// printf("%s\n", c);
	// c = ft_get_next_line(fd);
	// printf("%s\n", c);
	// c = ft_get_next_line(fd);
	// printf("last: %s", c);
	// c = ft_get_next_line(fd);
	// printf("%s\n", c);
}
