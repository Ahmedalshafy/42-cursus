/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:02:15 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/21 14:51:47 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * strlen(src) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*buf(char c, int j, char *buffer, char *s)
{
	j = j + BUFFER_SIZE;
	buffer[BUFFER_SIZE] = c;
	buffer[BUFFER_SIZE + 1] = 0;
	s = (char *) realloc(s, (j + 1));
	strcat(s, buffer);
	free(buffer);
	buffer = (char *) calloc((BUFFER_SIZE + 1), sizeof(char));
	return (s);
}

char	*ft_get_next_line(int fd)
{
	size_t			i;
	static int		j;
	char			*buffer;
	char			c;
	char			*s;

	buffer = (char *) calloc((BUFFER_SIZE + 1), sizeof(char));
	s = (char *) calloc((BUFFER_SIZE + 1), sizeof(char));
	i = 0;
	j = 0;
	while (read(fd, &c, 1) != 0)
	{
		if (c != '\n' && i < (BUFFER_SIZE))
		{
			buffer[i] = c;
			i++;
		}
		else if (c != '\n' && i == (BUFFER_SIZE))
		{
			buf(c, j, buffer, s);
			i = 0;
		}
		else
		{
			buf(c, j, buffer, s);
			break ;
		}
	}
	return (s);
}

int	main(void)
{
	int		fd;
	char	*c;
	char	*s;
	int		i;

	fd = open("/Users/aalshafy/Desktop/cursusdraft/ft_getnextline/new.txt", O_RDWR | O_CREAT, 0640);
	s = ft_get_next_line(fd);
	printf("%s\n", s);
	c = ft_get_next_line(fd);
	printf("%s\n", c);
	c = ft_get_next_line(fd);
	printf("%s\n", c);
	c = ft_get_next_line(fd);
	printf("%s\n", c);
	c = ft_get_next_line(fd);
	printf("%s\n", c);
	c = ft_get_next_line(fd);
	printf("last: %s", c);
	c = ft_get_next_line(fd);
	printf("%s\n", c);
}
