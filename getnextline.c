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

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 3

#endif

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

char	*buf(int j, char *buffer, int fd)
{
    int     i;
    char    c;

    i = 0;
    while (read(fd, &c, 1))
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
            return (buffer);
		}
		else
		{
			j = 0;
            buffer[i] = c;
            buffer[i + 1] = 0;
            printf("buf: %s\n", buffer);
            return (buffer);
		}
    }
	return (NULL);
}

char	*ft_get_next_line(int fd)
{
	static int		j;
	char			*buffer;
	char			*s;

	buffer = (char *) calloc((BUFFER_SIZE), sizeof(char));
    s = (char *) calloc((BUFFER_SIZE), sizeof(char));
    j = 0;
    while (buf(j, buffer, fd) && j)
    {
        // s = realloc(s, j);
        printf("buf2: %s\n", buffer);
        strcat(s, buffer);
        // free(buffer);
    }
    printf("buf3: %s\n", buffer);
    if (!buffer)
        return (NULL);
    if (j == 0)
    {
        strcat(s, buffer);
        free(buffer);
    }

    printf("s: %s\n", s);
    return (s);
}

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("new.txt", O_RDWR | O_CREAT, 0640);
	s = ft_get_next_line(fd);
	printf("final %s\n", s);
	free(s);
	// c = ft_get_next_line(fd);
	// printf("%s\n", c);
	// free(c);
	// c = ft_get_next_line(fd);
	// printf("%s\n", c);
	// free(c);
	// c = ft_get_next_line(fd);
	// printf("%s\n", c);
	// free(c);
	// c = ft_get_next_line(fd);
	// printf("%s\n", c);
	// c = ft_get_next_line(fd);
	// printf("last: %s", c);
	// c = ft_get_next_line(fd);
	// printf("%s\n", c);
}
