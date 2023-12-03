/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:02:15 by aalshafy          #+#    #+#             */
/*   Updated: 2023/12/02 19:03:59 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line(char *line, char *buffer)
{
	char	*new;

	new = ft_strjoin(line, buffer);
	if (new == NULL)
	{
		free(line);
		free(buffer);
		return (NULL);
	}
	free(line);
	return (new);
}

char	*bufread(char *buffer, int fd)
{
	int		i;
	char	c;

	i = -1;
	while (read(fd, &c, 1) > 0)
	{
		if (c != '\n' && i < BUFFER_SIZE - 1)
			buffer[++i] = c;
		else
		{
			buffer[++i] = c;
			buffer[++i] = 0;
			return (buffer);
		}
	}
	if (i == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[++i] = 0;
	return (buffer);
}

int	checkln(char *buffer)
{
	int	i;

	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
			return (i);
	}
	return (-1);
}

char	*buffer_copy(char *buffer, char *s, int fd)
{
	buffer = bufread(buffer, fd);
	if (!buffer)
	{
		free(buffer);
		free(s);
		return (NULL);
	}
	while (checkln(buffer) == -1)
	{
		s = line(s, buffer);
		if (!s)
			return (NULL);
		buffer = bufread(buffer, fd);
		if (!buffer)
		{
			free(buffer);
			return (s);
		}
	}
	s = line(s, buffer);
	if (!s)
		return (NULL);
	free(buffer);
	return (s);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	char			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) ft_calloc((BUFFER_SIZE + 2), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	line = (char *) ft_calloc(sizeof(char), 1);
	if (line == NULL)
	{
		free(buffer);
		return (NULL);
	}
	temp = buffer_copy(buffer, line, fd);
	if (temp == NULL)
	{
		return (NULL);
	}
	return (temp);
}

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	char	*s;
// 	int		i;

// 	fd1 = open("new.txt", O_RDWR | O_CREAT, 0640);
// 	fd2 = open("1char.txt", O_RDWR | O_CREAT, 0640);
// 	fd3 = open("text.txt", O_RDWR | O_CREAT, 0640);
// 	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
// 		printf("%i - %i - %i\n", fd1, fd2, fd3);
// 	i = 0;
// 	s = get_next_line(fd3);
// 	printf("%s\n", s);
// 	free(s);
// 	s = get_next_line(fd2);
// 	printf("2- %s\n", s);
// 	free(s);
// 	s = get_next_line(fd3);
// 	printf("3- %s\n", s);
// 	free(s);
// 	s = get_next_line(fd1);
// 	printf("1- %s\n", s);
// 	free(s);
// 	s = get_next_line(fd2);
// 	printf("2- %s\n", s);
// 	free(s);
// 	s = get_next_line(fd1);
// 	printf("1- %s\n", s);
// 	free(s);
// 	s = get_next_line(fd3);
// 	printf("3- %s\n", s);
// 	free(s);
// 	// while (s)
// 	// {
// 	// 	printf("%s", s);
// 	// 	s = get_next_line(fd3);
// 	// 	free(s);
// 	// 	i++;
// 	// }
// }
