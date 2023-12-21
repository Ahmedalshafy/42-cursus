/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:05:47 by aalshafy          #+#    #+#             */
/*   Updated: 2023/12/15 15:47:21 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;
	int				j;

	j = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_calloc(sizeof(char), 1);
	if (!line)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (free(line), NULL);
	line = check(buffer, line, fd, &j);
	if (line == NULL)
		return (free(buffer), buffer = NULL, free(line), NULL);
	if (j <= 0 && buffer[0] != 0 && buffer != NULL)
		return (line);
	if (j <= 0 && buffer[0] == 0)
		return (free(buffer), buffer = NULL, line);
	return (line);
}

char	*check(char *buffer, char *line, int fd, int *j)
{
	int		l;

	if (buffer[0] != 0 && buffer != NULL)
	{
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		l = checkln(line);
		if (l != -1)
			return (buffer_edit(buffer), line);
	}
	line = ft_read(buffer, line, fd, j);
	if (!line)
		return (free(line), NULL);
	return (line);
}

char	*ft_read(char *buffer, char *line, int fd, int *j)
{
	int		l;
	int		i;

	*j = 1;
	while (*j > 0 && checkln(line) == -1)
	{
		*j = read(fd, buffer, BUFFER_SIZE);
		if (*j == 0)
		{
			if (buffer[0] != 0 && buffer != NULL)
				return (buffer[0] = 0, line);
			return (free(line), NULL);
		}
		if (*j < 0)
			return (buffer[0] = 0, free(line), NULL);
		buffer[*j] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(line), NULL);
		l = checkln(buffer);
		i = ft_strlen(buffer);
		if (l != -1)
			return (buffer_edit(buffer), line);
	}
	return (buffer[0] = 0, NULL);
}
