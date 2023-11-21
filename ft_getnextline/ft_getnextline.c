/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:02:15 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/21 14:56:07 by aalshafy         ###   ########.fr       */
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

char	*ft_get_next_line(int fd)
{
	size_t		i;
	size_t		j;
	char		*buffer;
	char		c;
	char		*s;

	buffer = (char *) malloc((BUFFER_SIZE * sizeof(char)) + 1);
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
			j = j + i;
			buffer[i] = c;
			buffer[i + 1] = 0;
			s = (char *) realloc(s, (j + 1));
			strcat(s, buffer);
			i = 0;
			free(buffer);
			buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		}
		else
		{
			j = j + i;
			buffer[i] = c;
			buffer[i + 1] = 0;
			s = (char *) realloc(s, (j + 1));
			strcat(s, buffer);
			i = 0;
			free(buffer);
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
	printf("%s", s);
	s = ft_get_next_line(fd);
	printf("%s", s);
	s = ft_get_next_line(fd);
	printf("%s", s);
	s = ft_get_next_line(fd);
	printf("%s", s);
	s = ft_get_next_line(fd);
	printf("%s", s);
	// s = ft_get_next_line(fd);
	// printf("%s\n", s);
	// s = ft_get_next_line(fd);
	// printf("%s\n", s);
	// s = ft_get_next_line(fd);
	// printf("%s\n", s);
	// s = ft_get_next_line(fd);
	// printf("%s\n", s);
	// s = ft_get_next_line(fd);
	// printf("%s\n", s);
}
