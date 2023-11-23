/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:02:15 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/23 20:07:43 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

//  need to reduce get next line lines
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
	s = (char *) realloc(s, (j + 1));
	if (s == NULL)
		return (NULL);
	strcat(s, buffer);
	return (s);
}

void	newset(char c, int *i, char *buffer, char *s)
{
	static int	j;

	buffer[*i] = c;
	buffer[*i + 1] = 0;
	j = j + *i;
	s = bufcpy(j, buffer, s);
}

void cond(char c, int *i, char *buffer, char *s)
{
	if (++(*i) < (BUFFER_SIZE) && c != '\n')
		buffer[*i] = c;
	else if (c != '\n' && *i == (BUFFER_SIZE))
	{
		newset(c, &i, buffer, s);
		*i = -1;
	}
	else if (c == '\n')
	{
		newset(c, &i, buffer, s);
		free(buffer);
	}
	
}

char	*ft_get_next_line(int fd)
{
	static int		i;
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
	while (read(fd, &c, 1) != 0)
	{
		cond(c, &i, buffer, s);
		if (c == '\n')
			return (s);
	}
	if (buffer[BUFFER_SIZE] || i != -1)
	{
		newset(c, &i, buffer, s);
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
}