/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:05:47 by aalshafy          #+#    #+#             */
/*   Updated: 2023/12/14 16:32:50 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <string.h>

char	*get_next_line(int fd)
{
	static char		*buffer[1023];
	char			*line;
	int				j;

	j = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_calloc(sizeof(char), 1);
	if (!line)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer[fd])
		return (free(line), NULL);
	line = check(buffer[fd], line, fd, &j);
	if (line == NULL)
		return (free(buffer[fd]), free(line), buffer[fd] = NULL, NULL);
	if (j <= 0 && buffer[fd][0] != 0)
		return (line);
	if (j <= 0 && buffer[fd][0] == 0)
		return (free(buffer[fd]), buffer[fd] = NULL, line);
	return (line);
}

char	*check(char *buffer, char *line, int fd, int *j)
{
	int		l;

	if (buffer[0] != 0)
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
			if (buffer[0] != 0)
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

// int	main(void)
// {
// 	int		fd1;
// 	char	*s;
// 	int		i;

// 	fd1 = open("variable_nls.txt", O_RDWR | O_CREAT, 0640);

// 		s = get_next_line(fd1);
// 		// s = get_next_line(fd1);
// 		// printf("%s", s);
// 		// free(s);
// 		// s = get_next_line(fd1);
// 		// printf("%s", s);
// 	i = 1;
// 	while (s)
// 	{
// 		printf("%i- %s", i, s);
// 		free(s);
// 		s = get_next_line(fd1);
// 		i++;
// 	}
// 	free(s);
	
// }