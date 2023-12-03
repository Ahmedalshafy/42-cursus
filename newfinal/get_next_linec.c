/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:02:15 by aalshafy          #+#    #+#             */
/*   Updated: 2023/12/03 17:23:05 by aalshafy         ###   ########.fr       */
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

char	*lineread(char *buffer, int fd)
{
	int		i;
	char	*nline;
	char	*nbuf;

	i = -1;
	nline = (char *) ft_calloc(sizeof(char), 1);
	if (nline == NULL)
		return (NULL);
	// printf("\n\n#######: %s\n\n", buffer);
	nline = line(nline, buffer);
	// printf("\n\n********: %s\n\n", nline);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		i = checkln(buffer);
		if (i == -1)
			nline = line(nline, buffer);
		else
		{
			nbuf = buffer_edit(buffer);
			nline = line(nline, nbuf);
			if (!nline)
				return (NULL);
			free (nbuf);
			return (nline);
		}
	}
	free (nline);
	return (NULL);
}

char	*buffer_edit(char *buffer)
{
	int		i;
	int		j;
	char	*cpy;

	i = checkln(buffer);
	cpy = malloc(i);
	if (!cpy)
		return (NULL);
	j = 0;
	while (j < i)
	{
		cpy[j] = buffer[j];
		j++;
	}
	cpy[j] = 0;
	return (cpy);
}

char	*newbuf(char *buffer)
{
	int		len;
	int		i;
	int		j;
	char	*nwbuf;

	// printf("\n\n&&&&&&&&&: %s\n\n", buffer);
	// buffer isnt termineted
	len = ft_strlen(buffer); 
	i = checkln(buffer);
	nwbuf = malloc(len - i);
	if (!nwbuf)
		return (NULL);
	j = -1;
	while (buffer[++i])
		nwbuf[++j] = buffer[i];
	nwbuf[++j] = 0;
	free(buffer);
	return (nwbuf);
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

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer != NULL)
	{
		if (checkln(buffer) != -1)
		{
			line = buffer_edit(buffer);
			if (!line)
			{
				free (buffer);
				return (NULL);
			}
			buffer = newbuf(buffer);
			printf("\n\n#######: %s\n\n", buffer);
			return (line);
		}
	}
	else if (buffer == NULL)
		buffer = (char *) ft_calloc(BUFFER_SIZE, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	line = lineread(buffer, fd);
	if (!line)
	{
		free (buffer);
		return (NULL);
	}
	buffer = newbuf(buffer);
	printf("\n\n^^^^^^^^^^: %s\n\n", buffer);
	if (buffer == NULL)
		return (NULL);
	return (line);
}

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*s;
	int		i;

	fd1 = open("new.txt", O_RDWR | O_CREAT, 0640);
	fd2 = open("1char.txt", O_RDWR | O_CREAT, 0640);
	fd3 = open("text.txt", O_RDWR | O_CREAT, 0640);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		printf("%i - %i - %i\n", fd1, fd2, fd3);
	i = 0;
	s = get_next_line(fd3);
	// printf("%s\n", s);
	// free(s);
	// s = get_next_line(fd2);
	// printf("2- %s\n", s);
	// free(s);
	// s = get_next_line(fd3);
	// printf("3- %s\n", s);
	// free(s);
	// s = get_next_line(fd1);
	// printf("1- %s\n", s);
	// free(s);
	// s = get_next_line(fd2);
	// printf("2- %s\n", s);
	// free(s);
	// s = get_next_line(fd1);
	// printf("1- %s\n", s);
	// free(s);
	// s = get_next_line(fd3);
	// printf("3- %s\n", s);
	// free(s);
	while (s)
	{
		printf("%s", s);
		s = get_next_line(fd3);
		i++;
	}
	free(s);
}
