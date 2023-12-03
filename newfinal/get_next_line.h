/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:34:33 by aalshafy          #+#    #+#             */
/*   Updated: 2023/12/03 14:49:15 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 1

#endif

#ifndef GNL

# define GNL

char	*bufread(char *buffer, int fd);
char	*line(char *line, char *buffer);
int		checkln(char *buffer);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char	*lineread(char *buffer, int fd);
char	*buffer_edit(char *buffer);
char	*newbuf(char *buffer);

#endif