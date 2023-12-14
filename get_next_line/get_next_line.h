/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:34:33 by aalshafy          #+#    #+#             */
/*   Updated: 2023/12/14 13:48:55 by aalshafy         ###   ########.fr       */
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

int		checkln(char *buffer);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
char	*lineread(char *buffer, char *line, int fd, int *j);
char	*ft_read(char *buffer, char *line, int fd, int *j);
char    *check(char *buffer, char *line, int fd, int *j);
void	*ft_memmove(void *dst, const void *src, size_t n);
void    buffer_edit(char *buffer);

