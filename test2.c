/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:02:15 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/23 11:21:49 by aalshafy         ###   ########.fr       */
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

char	*bufcpy(int j, char *buffer, char *s)
{
	printf("j cpy: %i\n", j);
	printf("addr cpy: %p\n", buffer);
	printf("buf cpy: %s\n", buffer);
	s = (char *) realloc(s, (j + 1));
	if (s == NULL)
		return (NULL);
	strcat(s, buffer);
	printf("s1 in cpy: %s\n", s);
	free(buffer);
	buffer = (char *) calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	printf("s in cpy: %s\n", s);
	return (s);
}

char	*ft_get_next_line(int fd)
{
	size_t			i;
	static int		j;
	static char			*buffer;
	char			c;
	char			*s;

	buffer = (char *) calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	printf("addr main: %p\n", buffer);
	s = (char *) calloc(sizeof(char), 1);
	if (s == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (read(fd, &c, 1) != 0)
	{
		if (c != '\n' && ++i < (BUFFER_SIZE))
		{
			printf("i main: %zu\n", i);
			buffer[i] = c;
		}
			
		else if (c != '\n' && i == (BUFFER_SIZE))
		{
			printf("i main: %zu\n", i);
			buffer[i] = c;
			printf("buf2 main: %s\n", buffer);
			j = j + i;
			s = bufcpy(j, buffer, s);
			i = -1;
		}
		else if (c == '\n' && i == (BUFFER_SIZE))
		{
			j = j + i;
			buffer[i] = c;
			s = bufcpy(j, buffer, s);
			free(buffer);
			return (s);
		}
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
